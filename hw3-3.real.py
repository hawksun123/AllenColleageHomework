# Python3 default encoding is UTF-8
# 統一發票兌獎:
# 統一發票是一個八位數字(整數)的對獎方式，有一個特別獎號，一個特獎號及三個頭獎獎號，和數個增開六獎(三位數)
# 獎金則是根據下面規則給付:
# 特別獎:和特別獎號碼完全相同      獎金10000000 元
# 特獎:和特獎號碼完全相同          獎金 2000000 元
# 頭獎:和頭獎號碼完全相同          獎金  200000 元
# 二獎:和頭獎號碼最後 7 位數字相同，獎金   40000 元
# 三獎:和頭獎號碼最後 6 位數字相同，獎金   10000 元
# 四獎:和頭獎號碼最後 5 位數字相同，獎金    4000 元
# 五獎:和頭獎號碼最後 4 位數字相同，獎金    1000 元
# 六獎:和頭獎號碼最後 3 位數字相同，獎金     200 元
# 增開六獎:和增開六獎號碼完全相同   獎金     200 元
#
# 程式執行輸出畫面舉例如下:

# 特別獎號碼
# 請輸入第一個號碼:41275633
# 特獎號碼
# 請輸入第一個號碼:56188690
# 頭獎號碼
# 請輸入第一個號碼:68285428
# 請輸入第二個號碼:12031965
# 請輸入第三個號碼:92658431
# 使用者發票號碼
# 請輸入第1個號碼:41275633
# 請輸入第2個號碼:92631965
# 請輸入第3個號碼:51868431
# 獎金 10005000 元
#
# Copyright (c) 2016 by Hawk Sun

# No constant value in Python, just name a variable in all capital letters to differentiate from normal
# variable
DEBUG = 1

SPECIAL_PRICE_COUNT = 1
GRAND_PRICE_COUNT = 1
FIRST_PRICE_COUNT = 3
EXTRA_SIXTH_PRICE_CNT = 3
RECEIPT_LEN = 8
SUCCESS = 8
DIGITS_COMPARE_TIMES = RECEIPT_LEN - 3 + 1

chtDigits = ["一", "二", "三","四","五","六","七","八","九"]
price = [10000000, 2000000, 200000, 40000, 10000, 4000, 1000, 200, 200]
total = 0

def InputPriceReceiptNo(COUNT):
  list = [] # create an empty list
  for loop in range (0, COUNT):
    list.append(input("請輸入第" + chtDigits[loop] + "個號碼:"))
  return list

def InputUserReceiptNo():
  list = [] # create an empty list
  loop = 0
  strUserNo = "Begin"
  while (strUserNo != ""):
    loop += 1
    strUserNo = input("請輸入第" + str(loop) + "個號碼:")
    if (strUserNo !="") : list.append(strUserNo)
  return list

print("特別獎號碼")
specialPrice = InputPriceReceiptNo(SPECIAL_PRICE_COUNT) # create a global list named specialPrice

print("特獎號碼")
grandPrice = InputPriceReceiptNo(GRAND_PRICE_COUNT) # create a global list named grandPrice

print("頭獎號碼")
firstPrice = InputPriceReceiptNo(FIRST_PRICE_COUNT) # create a global list named firstPrice

print("增開六獎號碼")
extra6Price = InputPriceReceiptNo(EXTRA_SIXTH_PRICE_CNT) # create a global list named extra6Price

print("使用者發票號碼")
userNo = InputUserReceiptNo()

#if DEBUG
#  specialPrice = ["91909013"]
#  grandPrice = ["95976127"]
#  firstPrice = ["54845444", "41876525", "86331065"]
#  userNo = ["91909013","95976127","41876525","16331065","22845444"]
#  extra6Price = ["013", "444", "555"]

for loop1 in range(0, len(userNo)):
  # 特別獎獎金計算
  for loop2 in range(0, SPECIAL_PRICE_COUNT):
    if (userNo[loop1] == specialPrice[loop2]): # win
      total += price[0]
      if DEBUG:
        print("(特別獎)累積獎金%d元\n" % total)
  # loop2

  for loop2 in range(0, GRAND_PRICE_COUNT):
    if (userNo[loop1] == grandPrice[loop2]): # win
      total += price[1]
      if DEBUG:
        print("(特獎)累積獎金%d元\n" % total)
  # loop2

  # 頭獎~六獎 獎金計算
  for loop2 in range(0, FIRST_PRICE_COUNT):
    for loop3 in range(0, DIGITS_COMPARE_TIMES):
      if ((userNo[loop1][loop3:]) == (firstPrice[loop2][loop3:])): # win
        total += price[2 + loop3]
        if DEBUG:
          print("userNo[%d][%d:] = %s, firstPrice[%d][%d:] = %s\n"
                % (loop1, loop3, userNo[loop1][loop3:], loop2, loop3, firstPrice[loop2][loop3:]))
          print("(頭獎~六獎)累積獎金%d元\n" % total)
        break # exit the loop3, means to compare the next number
 

  for loop2 in range(0, EXTRA_SIXTH_PRICE_CNT):
    print(userNo[loop1][-3:])
    if (userNo[loop1][-3:] == extra6Price[loop2]): # win
      total += price[-1]
      if DEBUG:
        print("(增開六獎)累積獎金%d元\n" % total)
  # loop2
# loop1

print("\n獎金%d元" % total, end=" ")


