@REM That's the way i run the experiment
@REM Syntax is <executable> <dimension> <precizion> <functin_id> <algorithm_id> <result path>
@REM functin_id select value according
@REM    1 -> De Jong 1 function
@REM    2 -> Schwefel's function
@REM    3 -> Rastrigin's function
@REM    4 -> Michalewicz's function
@REM algorithm_id select value according
@REM    1 -> HillClimbing First Improvement
@REM    2 -> HillClimbing Best Improvement
@REM    3 -> SimulatedAnnealing

@REM Run foreach dimention for HillClimbing First Improvement
T1.exe 5 5 1 1 "result_jong_hcf.txt"
T1.exe 10 5 1 1 "result_jong_hcf.txt"
T1.exe 30 5 1 1 "result_jong_hcf.txt"

@REM Run foreach dimention for HillClimbing Best Improvement
T1.exe 5 5 1 2 "result_jong_hcb.txt"
T1.exe 10 5 1 2 "result_jong_hcb.txt"
T1.exe 30 5 1 2 "result_jong_hcb.txt"

@REM Run foreach dimention for SimulatedAnnealing
T1.exe 5 5 1 3 "result_jong_sa.txt"
T1.exe 10 5 1 3 "result_jong_sa.txt"
T1.exe 30 5 1 3 "result_jong_sa.txt"