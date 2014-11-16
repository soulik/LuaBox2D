local function testFile(name)
	local fname = ("test_%s.lua"):format(name)
	return pcall(loadfile(fname))
end

--print(testFile('Vec2'))
--print(testFile('VertexArray'))
--print(testFile('World'))
print(testFile('Body'))
