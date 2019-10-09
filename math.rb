#a#! /usr/bin/env ruby
#require 'numo/narray'
#include Numo
#encoding : UTF-8

#参考
#https://maehrm.hatenablog.com/entry/20100730/p1a
#http://unageanu.hatenablog.com/entry/20090312/1236862932

class Array
  # 要素をto_iした値の平均を算出する
  def avg
    inject(0.0){|r,i| r+=i.to_i }/size
  end
  # 要素をto_iした値の分散を算出する
  def variance
    a = avg
    inject(0.0){|r,i| r+=(i.to_i-a)**2 }/size
  end
  # 要素をto_iした値の標準偏差を算出する
  def stddev
    Math.sqrt(variance)
  end
	
end


scie = [65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70]
eng = [44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84]

#savg = self.mean(scie) 
#sstddev = self.stddev(scie)
#ssum = self.sum(scie)

#print ("sum = %lf\n"ssum)
#print ("stddev = %lf\n"sstddev)
#print ("avg = %lf\n"sacg")
	
a = scie.sum
b = scie.avg
c = scie.stddev

puts "/////////////////about Sciense////////////////////"
print ("sum = ")
puts c

print ("avarage  = ")
puts b

print ("stddev = ")
puts c

#偏差値

print "score\tTscore\n"
scie.each do |x|
	ss = (x - b ) / c * 10 + 50
	print "#{x}\t#{ss}\n"
end

#sort

print "-------------ranking!--------------\n"
scie.sort!.reverse!
p scie


a = eng.sum
b = eng.avg
c = eng.stddev

puts "///////////////////about English//////////////////"
print ("sum = ")
puts c

print ("avarage  = ")
puts b

print ("stddev = ")
puts c

#偏差値

print "score\tTscore\n"
eng.each do |x|
	ss = (x - b ) / c * 10 + 50
	print "#{x}\t#{ss}\n"
end

#sort

print "-------------ranking!--------------\n"

eng.sort!.reverse!
p eng
