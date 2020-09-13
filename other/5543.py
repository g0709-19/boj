INPUT_COUNT = 5
SET_DISCOUNT = 50
BURGER = {'상덕':0, '중덕':1, '하덕':2}
DRINK = {'콜라':3, '사이다':4}
inputs = [int(input()) for i in range(INPUT_COUNT)]
prices = [inputs[burger] + inputs[drink] - SET_DISCOUNT for burger in BURGER.values() for drink in DRINK.values()]
print(min(prices))