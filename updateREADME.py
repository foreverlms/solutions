#!/usr/bin/env python3
# _*_ coding: utf-8 _*_
from os import path
import argparse
import re

total = 0;
format_str = ''
format_str_cpp = "|{num}|{title}|{difficulty}|[{lang}](https://github.com/foreverlms/solutions/blob/master/cpp/src/leetcode{num}.cpp)|{run_time}|{mind}|"
format_str_java = " "#待定
format_str_python = "|{num}|{title}|{difficulty}|[{lang}](https://github.com/foreverlms/solutions/blob/master/python/leetcode{num}.py)|{run_time}|{mind}|"


def get_parser():
	parser = argparse.ArgumentParser("更新solution的README.md")
	parser.add_argument('title',metavar='TITLE',type=str,help="所添加题目")
	parser.add_argument('-n','--num',type=int,required=True,help="题号")
	parser.add_argument('-l','--lang',type=str,default="cpp",help="语言,cpp/java/c/python",choices=['cpp',"python","java"])
	parser.add_argument('-d','--difficulty',type=str,default="Easy",help="题目难度等级，easy/medium/difficult")
	parser.add_argument('-r','--run_time',type=str,help="runtime和排名占比",required=True)
	parser.add_argument('-m','--mind',type=str,default="见链接",help="解法思路")
	parser.add_argument('-a','--add',action='store_true',help="是否题目数目加一？默认不加一")

	return parser

parser = get_parser()
args = vars(parser.parse_args())

title_ = args['title']
num_ = args['num']
lang_ = args['lang']
difficulty_ = args['difficulty']
run_time_ = args['run_time']
mind_ = args['mind']

def add_one():
	#已做题目数： **29**\n
	num_str = "已做题目数： **{total_}**\n".format(total_=total)
	with open("./README.md","a+",encoding="utf8") as f:
		pass

	re.sub(r"(?P<num_>\d{2})",str(int('\\g<num_>')+1),line)

def format_cpp_str():
	format_str_cpp.format(num=num_,title=title_,lang=lang_,difficulty=difficulty_,run_time=run_time_,mind=mind_)

def format_java_str():
	format_str_java.format(num=num_,title=title_,lang=lang_,difficulty=difficulty_,run_time=run_time_,mind=mind_)

def format_python_str():
	format_str_python.format(num=num_,title=title_,lang=lang_,difficulty=difficulty_,run_time=run_time_,mind=mind_)


if lang_ == "cpp":
	format_str = "|{num}|{title}|{difficulty}|[{lang}](https://github.com/foreverlms/solutions/blob/master/cpp/src/leetcode{num}.cpp)|{run_time}|{mind}|\n".format(num=num_,title=title_,lang=lang_,difficulty=difficulty_,run_time=run_time_,mind=mind_)
elif lang_ == "java":
	pass
elif lang_ == 'python':
	format_str = "|{num}|{title}|{difficulty}|[{lang}](https://github.com/foreverlms/solutions/blob/master/python/leetcode{num}.py)|{run_time}|{mind}|\n".format(num=num_,title=title_,lang=lang_,difficulty=difficulty_,run_time=run_time_,mind=mind_)

with open("./README.md","a+",encoding="utf8") as f:
	f.write(format_str)

data = ""
if args['add']:
	with open("./README.md","r",encoding="utf8") as f :
		for line in f.readlines():
			# print(i)
			matcher = re.match(r'已做题目数： \*\*(\d{2})\*\*\n',line)
			if matcher:
				total = int(matcher.group(1)) +1;
				num_str = "已做题目数： **{total_}**\n".format(total_=total)
				line = num_str
			data += line

	with open("./README.md","w",encoding="utf8") as f:
		f.write(data)