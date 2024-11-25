# Problem 3368: First Letter Capitalization
# https://leetcode.com/problems/first-letter-capitalization/

import pandas as pd

def process_text(user_content: pd.DataFrame) -> pd.DataFrame:

    # 將原本的 content_text 改為 original_text
    user_content = user_content.rename(columns={'content_text': 'original_text'})
    # 把 original_text 的資料首字大寫後加入 converted_text 欄位
    user_content['converted_text'] = (user_content.original_text.apply(lambda x: x.title()))

    return user_content