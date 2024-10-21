import os
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

def load_csv(name:str) -> pd.DataFrame:
    try:
        df = pd.read_csv(name, encoding="cp949") #윈도우에서 작성된 파일이기 때문에 기본 구성이 cp949입니다. 리눅스에서는 utf-8을 사용합니다. 그렇기 때문에, 아래서 다시 선언합니다.
        print(f"'{os.path.basename(name)}'이 로드되었습니다.")
        return df
    except FileNotFoundError as e:
        print("해당 파일이 존재하지 않습니다.")
        return pd.DataFrame("[[]]")

def survived_probability():
    df=load_csv('../data/titan/titanic.csv')

    size = []

    live = len(df[df['Survived'] == 1])    #len을 통해 survived 칼럼에 1인것의 항목의 갯수를 담는다.
    die = len(df[df['Survived'] == 0])     #len을 통해 survived 칼럼에 0인것의 항목의 갯수를 담는다.

    size.append(live)         #size리스트에 위에서 정리한것을 담는다.
    size.append(die)          #size리스트에 위에서 정리한것을 담는다.

    color = ['crimson', 'yellow']         #color리스트에 진홍색과 노란색을 담는다.
    plt.axis('equal')                     # 그래프의 x축과 y축의 스케일을 동일하게 만든다. 파이형의 경우 실제 원형으로 보이게한다.
    plt.pie(size, labels=['live', 'die'], autopct='%.1f%%', colors=color, startangle=90)  #파이형 그래프를 만들고 startangle을 통하여 시작점을 90도 이동을하여 12시 방향부터 시작한다.
    plt.title("survive")              #차트의 이름을 survive로 한다 .
    plt.show()

def survive_gender():
    df = load_csv('../data/titan/titanic.csv')

    size = []

    live_male = len(df[(df['Survived'] == 1) & (df['Sex'] == 'male')])           #len을 통해 survived 칼럼에 1과 성별이 male을 동시에 부합하는것의 항목의 갯수를 담는다.
    live_female = len(df[(df['Survived'] == 1) & (df['Sex'] == 'female')])       #len을 통해 survived 칼럼에 1과 성별이 female을 동시에 부합하는것의 항목의 갯수를 담는다.

    size.append(live_male)               #size리스트에 위에서 정리한것을 담는다.
    size.append(live_female)             #size리스트에 위에서 정리한것을 담는다.

    color = ['crimson', 'yellow']         #color리스트에 진홍색과 노란색을 담는다.
    plt.axis('equal')                     # 그래프의 x축과 y축의 스케일을 동일하게 만든다. 파이형의 경우 실제 원형으로 보이게한다.
    plt.pie(size, labels=['male', 'female'], autopct='%.1f%%', colors=color, startangle=90)  #파이형 그래프를 만들고 startangle을 통하여 시작점을 90도 이동을하여 12시 방향부터 시작한다.
    plt.title("male vs female")         #차트의 이름을 male vs female로 한다 .
    plt.show()


def titanic_prob(target:str, live:bool=True, graph:str="pie"):
    df = load_csv('../data/titan/titanic.csv')
    if live: a, b = "Live", 1
    else: a, b = "Die", 0
    size = []

    unique_value:np.array = df[target].unique()
    unique_value = unique_value[~pd.isnull(unique_value)]
    for v in unique_value:
        v1 = len(df[(df['Survived'] == b) & (df[target] == v)])
        size.append(v1)

    if graph == "pie":
        plt.pie(size, labels=unique_value, autopct='%.1f%%', startangle=90)
        plt.title(f"{target} {a} Prob.")
        plt.show()
    elif graph == "bar":
        plt.bar(unique_value, size)
        plt.title(f"{target} {a} Prob.")
        plt.show()

def main() -> None:
    #survived_probability()
    # survive_gender()
    titanic_prob("Age", True, "bar")


if __name__ == "__main__":
    main()
