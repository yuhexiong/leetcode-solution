# Problem 3374: First Letter Capitalization II
# https://leetcode.com/problems/first-letter-capitalization-ii/

import pandas as pd

def capitalize_content(user_content: pd.DataFrame) -> pd.DataFrame:

    # 將原本的 content_text 改為 original_text
    user_content = user_content.rename(columns={'content_text': 'original_text'})
    # 把 original_text 的資料全部改成小寫再修改首字大寫後加入 converted_text 欄位
    user_content['converted_text'] = (user_content.original_text.apply(lambda x: x.lower().title()))

    return user_content