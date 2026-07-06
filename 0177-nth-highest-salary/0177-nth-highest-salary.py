import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    unique = employee['salary'].drop_duplicates().sort_values(ascending=False)

    if N < 1 or N > len(unique):
        nth_salary = None
    else:
        nth_salary = unique.iloc[N-1]

    column_name = f"getNthHighestSalary({N})"
    return pd.DataFrame({column_name: [nth_salary]})