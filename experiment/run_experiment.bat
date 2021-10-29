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

START run_jong.bat
START run_schwefel.bat
START run_rastrigin.bat
START run_michalewicz.bat
