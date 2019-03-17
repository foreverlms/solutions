#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author  : Bob Liao (codechaser@163.com)
# @Link    : https://github.com/coderchaser


import requests
import re
rq=requests.get("http://www.pythonchallenge.com/pc/def/ocr.html")

if rq.status_code == 200:
	html_text=rq.text

#正则匹配，非贪婪
pattern=re.compile(r'<!--(.*?)-->',re.S)
result_list=re.findall(pattern,html_text)
characters_str=result_list[1].replace("\n","")

count=set()
count_map={}
for char in characters_str :
	if char in count:
		pass
	else:
		count.add(char)
		count_map[char]=characters_str.count(char)

print(count_map)
# {'%': 6104, '$': 6046, '@': 6157, '_': 6112, '^': 6030, '#': 6115, ')': 6186, '&': 6043, '!': 6079, '+': 6066, ']': 6152, '*': 6034, '}': 6105, '[': 6108, '(': 6154, '{': 6046, 'e': 1, 'q': 1, 'u': 1, 'a': 1, 'l': 1, 'i': 1, 't': 1, 'y': 1}
print("http://www.pythonchallenge.com/pc/def/equality.html")
