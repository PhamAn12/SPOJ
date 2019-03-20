def Brute_Force(text, pattern)
	t = text.length
	pat = pattern.length

	# puts $t.class
	# puts text.class
	# puts text[2]
	for i in 0..(t-pat)
		j = 0
		while j < pat do
			if text[i+j] == pattern[j]
				j += 1 
			else
				break
			end	
		end	
		if j == pat
			puts (i.to_s + " ")
		end
	end	
		
end

Brute_Force("deabcfgabcabcabc", "abc")