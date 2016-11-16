# Python3 default encoding is UTF-8
# 統一發票兌獎: 
# 統一發票是一個八位數字(整數)的對獎方式，有三個特別獎號及三個頭獎獎號，獎金則是根據下
# 面規則給付:
# 和特別獎號碼完全相同        獎金 2000000 元 
# 和頭獎號碼完全相同          獎金  200000 元 
# 和頭獎號碼最後 7 位數字相同，獎金   40000 元 
# 和頭獎號碼最後 6 位數字相同，獎金   10000 元 
# 和頭獎號碼最後 5 位數字相同，獎金    4000 元 
# 和頭獎號碼最後 4 位數字相同，獎金    1000 元 
# 和頭獎號碼最後 3 位數字相同，獎金     200 元
# 
# 程式執行輸出畫面舉例如下: 
# 
# 特別獎號碼 
# 請輸入第一個號碼:56188690 
# 請輸入第二個號碼:14764245 
# 請輸入第三個號碼:41275633 
# 頭獎號碼 
# 請輸入第一個號碼:68285428 
# 請輸入第二個號碼:12031965 
# 請輸入第三個號碼:92658431 
# 使用者發票號碼 
# 請輸入第一個號碼:41275633 
# 請輸入第二個號碼:92631965 
# 請輸入第三個號碼:51868431 
# 獎金 2005000 元 
# 
# Copyright (c) 2016 by Hawk Sun

# No constant value in Python, just name a variable in all capital letters to differentiate from normal 
# variable
DEBUG = 0 
SPECIAL_PRICE_COUNT = 3
FIRST_PRICE_COUNT = 3
USER_NO_COUNT = 3
RECEIPT_LEN = 8
SUCCESS = 8
DIGITS_COMPARE_TIMES = RECEIPT_LEN - 3 + 1

price = [2000000, 200000, 40000, 10000, 4000, 1000, 200]
total = 0

def InputPriceReceiptNo(COUNT):
  chtDigits = ["一", "二", "三","四","五","六","七","八","九"]
  list = [] # create an empty list
  for loop in range (0, COUNT):
    list.append(input("請輸入第" + chtDigits[loop] + "個號碼:"))
  return list

print("特別獎號碼")
specialPrice = InputPriceReceiptNo(SPECIAL_PRICE_COUNT) # create a global list named specialPrice

print("頭獎號碼")
firstPrice = InputPriceReceiptNo(FIRST_PRICE_COUNT)

print("使用者發票號碼")
userNo = InputPriceReceiptNo(USER_NO_COUNT)

for loop1 in range(0, USER_NO_COUNT):
  # 特別獎獎金計算
  for loop2 in range(0, SPECIAL_PRICE_COUNT):
    if (userNo[loop1] == specialPrice[loop2]): # win
      total += price[0]
      if DEBUG:
        print("特別獎獎金%d元\n", total)
  # loop2

  # 頭獎獎金計算
  for loop2 in range(0, FIRST_PRICE_COUNT):
    for loop3 in range(0, DIGITS_COMPARE_TIMES):
      if ((userNo[loop1][loop3:]) == (firstPrice[loop2][loop3:])): # win
        total += price[loop3 + 1]
        if DEBUG:
          print("userNo[%d][%d:] = %s, firstPrice[%d][%d:] = %s\n" 
              % (loop1, loop3, userNo[loop1][loop3:], loop2, loop3, firstPrice[loop2][loop3:]))
          print("頭獎獎金%d元\n", total)
        break # exit the loop3, means to compare the next number
# loop1

print("\n獎金%d元", total)


