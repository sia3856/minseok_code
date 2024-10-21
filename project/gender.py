import os
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from scipy.ndimage import label


def load_csv(name:str) -> pd.DataFrame:
    try:
        df = pd.read_csv(name, encoding="cp949")
        print(f"'{os.path.basename(name)}'이 로드되었습니다.")
        return df
    except FileNotFoundError as e:
        print("해당 파일이 존재하지 않습니다.")
        return pd.DataFrame("[[]]")


def gender() -> None:

    df = load_csv("../data/gender/gender.csv")
    #print(df)
    test = 0

    m = df.iloc[1,3:104]
    f = df.iloc[1,106:]
    print(m)
    print(f)
    m = -m
    plt.style.use('ggplot')
    #plt.rcParams['axes.unicode_minus'] = False
    plt.pie(range(len(m)),m)
    plt.barh(range(len(f)),f)
    plt.show()





def main() -> None:
    gender()

if __name__ == '__main__':
    main()