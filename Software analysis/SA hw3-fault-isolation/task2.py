import os

fail_path = raw_input("Please input the fail tests path: ")
success_path = raw_input("Please input the success tests path: ")
#fail_path = "/home/cs6888/output/fail"
#success_path = "/home/cs6888/output/success"

fail_dir = os.walk(fail_path)
fail_list = [] # fail file store in this list
fail_line_dict = {} 
fail_statement_dict = {}


for path,dir_list,file_list in fail_dir:
  for file_name in file_list:
    fail_list.append(file_name)

for file in fail_list:
  f = open(fail_path + "/" + file, "r")
  lines = f.readlines()
  for line in lines:
    tmp = line.split(':',2)
    if len(tmp) == 3 and "-" not in tmp[0] and "#####" not in tmp[0]:
          if int(tmp[1]) in fail_line_dict:
            fail_line_dict[int(tmp[1])] = fail_line_dict.get(int(tmp[1])) + 1
            fail_statement_dict[int(tmp[1])] = tmp[2]
          else:
            fail_line_dict[int(tmp[1])] = 1
            fail_statement_dict[int(tmp[1])] = tmp[2]
  f.close()


success_dir = os.walk(success_path)
success_list = [] # success file store in this list
success_line_dict = {} 
success_statement_dict = {}
ttsuccess = 0

for path,dir_list,file_list in success_dir:
  for file_name in file_list:
    success_list.append(file_name)
    ttsuccess += 1

for file in success_list:
#  print(file)
  f = open(success_path + "/" + file, "r")
  lines = f.readlines()

  for line in lines:
    tmp = line.split(':',2)
    if len(tmp) == 3 and "-" not in tmp[0] and "#####" not in tmp[0]:
          if int(tmp[1]) in success_line_dict:
#              print(file)
              success_line_dict[int(tmp[1])] = success_line_dict.get(int(tmp[1])) + 1
              success_statement_dict[int(tmp[1])] = tmp[2]
          else:
#              print(file)
              success_line_dict[int(tmp[1])] = 1
              success_statement_dict[int(tmp[1])] = tmp[2]
  f.close()

print(fail_line_dict.keys())
print(fail_line_dict.values())
print(success_line_dict.keys())
print(success_line_dict.values())
print()

results = {}
for key, value in fail_line_dict.items():
  fail_index = key
  fail_s = value
  success_s = success_line_dict.get(fail_index)
  results[fail_index] = fail_s - (success_s/float(ttsuccess + 1))

dict_return = sorted(results.iteritems(), key = lambda results:results[1], reverse = True)
print(dict_return)

i = 1
while i < 11:
  k = dict_return[i][0]
  v = dict_return[i][1]
  print("top " + str(i) + ": line number: " + str(k)  + " statement: "+ str(fail_statement_dict.get(k)) + " #" + str(fail_line_dict.get(k)) + " #" + str(success_line_dict.get(k)) + " #" + str(ttsuccess) + " " + str(v))
  i += 1

