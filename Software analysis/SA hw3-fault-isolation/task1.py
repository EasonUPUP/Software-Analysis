import os
path = "/home/cs6888"
f = open("runtests.sh", "r")
lines = f.readlines()
test = 1
success = 0
fail = 0

if os.path.exists("tcas.gcda"):
        os.popen('rm -rf /home/cs6888/tcas.gcda;')

for line in lines:
                str1 = os.popen(line)
                detail = os.popen('gcov tcas.c;')
                print(str)
                for word in str1:
                        if "P" in word:
                            os.popen("cp -r /home/cs6888/tcas.c.gcov  /home/cs6888/output/success/test" + str(test) + ".gcov;")
                            success += 1
                            f_success = open("/home/cs6888/output/successPrint/" + str(test) + ".txt", 'a')
                            for item in detail:
                                f_success.write(item)
                                f_success.write('\n')
                            f_success.close()
                            
                        if "F" in word:
                            os.popen("cp -r /home/cs6888/tcas.c.gcov  /home/cs6888/output/fail/test" + str(test) + ".gcov;")
                            fail += 1
                            f_fail = open("/home/cs6888/output/failPrint/" + str(test) + ".txt", 'a')
                            for item in detail:
                                f_fail.write(item)
                                f_fail.write('\n')
                            f_fail.close()
                test += 1

f.close()
print("Total test: " + str(test))
print("Total success: " + str(success))
print("Total fail: " + str(fail))
