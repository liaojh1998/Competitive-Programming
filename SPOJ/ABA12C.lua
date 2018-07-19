function solve (n, k)
	local t = {}
	for i = 1, k do
		p = io.read('*n')
		table.insert(t, p)
	end
	local dp = {}
	dp[0] = {}
	dp[0][0] = 0
	for i = 1, k do
		dp[0][i] = -1
	end
	for i = 1, n do
		dp[i] = {}
		dp[i][0] = 0
		for j = 1, k do
			dp[i][j] = dp[i-1][j]
			for l = 1, k do
				if t[l] ~= -1 and j-l >= 0 and dp[i-1][j-l] ~= -1 and (dp[i][j] == -1 or dp[i-1][j-l] + t[l] < dp[i][j]) then
					dp[i][j] = dp[i-1][j-l] + t[l]
				end
			end
		end
	end
--[[
	for i = 0, n do
		for j = 0, k do
			io.write(dp[i][j] .. ' ')
		end
		io.write('\n')
	end
--]]
	return dp[n][k]
end

function main ()
	local t = io.read('*n')
	for i = 1, t do
		local n, k = io.read('*n', '*n')
		io.write(solve(n, k) .. '\n')
	end
end

main()