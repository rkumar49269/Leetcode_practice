import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores['rank'] = scores['score'].rank(method='dense', ascending=False)
    sorted_scores = scores.sort_values(by='score', ascending=False)

    return sorted_scores[['score', 'rank']]
    