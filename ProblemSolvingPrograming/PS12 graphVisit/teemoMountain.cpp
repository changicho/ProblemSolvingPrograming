private static final int startRowPoint = 0, startColPoint = 0, maxInt = Integer.MAX_VALUE / 2;
private static final int[] dir_row = { -1, -1, -1, 0, 0, 1, 1, 1 };
private static final int[] dir_col = { -1, 0, 1, -1, 1, -1, 0, 1 };

private static int row, col, jump, time, bestHigh;
private static int[][] map;

public static boolean can_move(int row1, int col1, int row2, int col2)
{
	if (row2 < 0 || row2 > map.length - 1 || col2 < 0 || col2 > map[0].length - 1)
		return false;
	else if (Math.abs(map[row1][col1] - map[row2][col2]) > jump)
		return false;
	return true;
}

public static int take(int row1, int col1, int row2, int col2)
{
	if (row1 == row2 && col1 == col2)
		return 0;
	int startHigh = map[row1][col1], endHigh = map[row2][col2];
	if (startHigh >= endHigh)
		return 1;
	else
		return (endHigh - startHigh) * (endHigh - startHigh);
}

public static void go_floyd()
{
	// distance[startRow][startCol][endRow][endCol]
	int[][][][] distance = new int[row][col][row][col];

	// init
	for (int i = 0; i < distance.length; i++)
	{
		for (int j = 0; j < distance[i].length; j++)
		{
			for (int k = 0; k < distance[i][j].length; k++)
			{
				Arrays.fill(distance[i][j][k], maxInt);
			}
		}
	}
	for (int i_row = 0; i_row < distance.length; i_row++)
	{
		for (int i_col = 0; i_col < distance[i_row].length; i_col++)
		{
			for (int j_row = 0; j_row < distance[i_row][i_col].length; j_row++)
			{
				for (int j_col = 0; j_col < distance[i_row][i_col][j_row].length; j_col++)
				{
					if ((i_row - j_row) * (i_row - j_row) + (i_col - j_col) * (i_col - j_col) <= 2)
					{
						distance[i_row][i_col][j_row][j_col] = take(i_row, i_col, j_row, j_col);
					}
				}
			}
		}
	}

	// floyd
	for (int k_row = 0; k_row < distance.length; k_row++)
	{
		for (int k_col = 0; k_col < distance[k_row].length; k_col++)
		{
			for (int i_row = 0; i_row < distance[k_row][k_col].length; i_row++)
			{
				for (int i_col = 0; i_col < distance[k_row][k_col][i_row].length; i_col++)
				{
					for (int j_row = 0; j_row < distance[k_row][k_col].length; j_row++)
					{
						for (int j_col = 0; j_col < distance[k_row][k_col][j_row].length; j_col++)
						{
							distance[i_row][i_col][j_row][j_col] = Math.min(distance[i_row][i_col][j_row][j_col], distance[i_row][i_col][k_row][k_col] + distance[k_row][k_col][j_row][j_col]);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int goTime = distance[startRowPoint][startColPoint][i][j];
			if (map[i][j] > bestHigh && goTime <= time)
			{
				int backTime = back_dijkstra(i, j);
				if (goTime + backTime <= time)
				{
					bestHigh = map[i][j];
				}
			}
		}
	}
}

public static int back_dijkstra(int row, int col)
{
	boolean[][] check = new boolean[map.length][map[0].length];
	int[][] distance = new int[map.length][map[0].length];
	for (int i = 0; i < distance.length; i++)
	{
		Arrays.fill(distance[i], maxInt);
	}

	int nowRow = row, nowCol = col, nextRow, nextCol, takeTime, shortDistance;
	distance[nowRow][nowCol] = 0;
	while (!check[nowRow][nowCol])
	{
		check[nowRow][nowCol] = true;
		for (int i = 0; i < dir_row.length; i++)
		{
			nextRow = nowRow + dir_row[i];
			nextCol = nowCol + dir_col[i];
			if (can_move(nowRow, nowCol, nextRow, nextCol))
			{
				takeTime = take(nowRow, nowCol, nextRow, nextCol);
				if (distance[nextRow][nextCol] > distance[nowRow][nowCol] + takeTime)
				{
					distance[nextRow][nextCol] = distance[nowRow][nowCol] + takeTime;
				}
			}
		}

		shortDistance = maxInt;
		for (int i = 0; i < check.length; i++)
		{
			for (int j = 0; j < check[i].length; j++)
			{
				if (!check[i][j] && shortDistance > distance[i][j])
				{
					shortDistance = distance[i][j];
					nowRow = i;
					nowCol = j;
				}
			}
		}
	}
	return distance[startRowPoint][startColPoint];
}

public static void main(String[] args)
{
	Scanner scan = new Scanner(System.in);
	while (scan.hasNext())
	{
		row = scan.nextInt();
		col = scan.nextInt();
		jump = scan.nextInt();
		time = scan.nextInt();
		map = new int[row][col];
		for (int i = 0; i < row; i++)
		{
			String line = scan.next();
			for (int j = 0; j < col; j++)
			{
				map[i][j] = line.charAt(j) - 'A';
			}
		}
		bestHigh = map[startRowPoint][startColPoint];
		go_floyd();
		System.out.println(bestHigh);
	}
	scan.close();
}