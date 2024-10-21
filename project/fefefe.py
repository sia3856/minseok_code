# Exam 11
import numpy as np;
import matplotlib.pyplot as plt;


# Functions
def fun_Sigmoid(x):
    y = 1 / (1 + np.exp(-x));
    return y;


def fun_backProCEMMT(W1, W2, X, D):
    alpha = 0.5;
    beta = 0.9;

    mmt1 = np.zeros(W1.shape);
    mmt2 = np.zeros(W2.shape);

    N = 100;

    for k in range(N):
        x = np.transpose(np.array([X[k, :]]));
        d = D[D.shape[0] - 1, k];

        v1 = np.dot(W1, x);
        y1 = fun_Sigmoid(v1);

        v = np.dot(W2, y1);
        y = fun_Sigmoid(v);

        e = d - y;
        delta = 1 * e;

        e1 = np.dot(np.transpose(W2), delta);
        delta1 = y1 * (1 - y1) * e1;

        dW1 = alpha * np.dot(delta1, np.transpose(x));
        mmt1 = dW1 + beta * mmt1;
        W1 = W1 + mmt1;
        # W1 = W1 + dW1;

        dW2 = alpha * np.dot(delta, np.transpose(y1));
        mmt2 = dW2 + beta * mmt2;
        W2 = W2 + mmt2;
        # W2 = W2 + dW2;

    return W1, W2;


# L Data
num_sample = 100;

x_posi = np.random.rand(1, num_sample);
y_posi = np.random.rand(1, num_sample);

d = np.zeros((1, num_sample));

for k in range(num_sample):
    if (y_posi[y_posi.shape[0] - 1, k] > np.float_power(x_posi[x_posi.shape[0] - 1, k], 2)):
        d[d.shape[0] - 1, k] = 1;
    else:
        d[d.shape[0] - 1, k] = 0;

X = np.concatenate((np.transpose(x_posi), np.transpose(y_posi)), axis=1);
D = d;

# Code
W1 = 2 * np.random.rand(15, 2) - 1;
W2 = 2 * np.random.rand(1, 15) - 1;

num_epoch = 1000;

for epoch in range(num_epoch):
    W1, W2 = fun_backProCEMMT(W1, W2, X, D);
    print('Epoch : ', epoch)

# Confirm

y_check = np.zeros((1, num_sample));

for k in range(num_sample):
    x = np.transpose(np.array([X[k, :]]));
    d = D[D.shape[0] - 1, k];

    v1 = np.dot(W1, x);
    y1 = fun_Sigmoid(v1);

    v = np.dot(W2, y1);
    y_check[y_check.shape[0] - 1, k] = fun_Sigmoid(v);

result = np.concatenate((np.transpose(D), np.round(np.transpose(y_check), 2)), axis=1);

print(result);

plt.figure(1)
plt.plot(x_posi, y_posi, 'ro')
plt.show()

# confiem plot
num_point = 100;

y_con_check = np.zeros((1, num_point));

x_c = np.random.rand(1, num_point);
y_c = np.random.rand(1, num_point);

X_c = np.concatenate((np.transpose(x_c), np.transpose(y_c)), axis=1);

for k in range(num_point):
    x_con = np.transpose(np.array([X_c[k, :]]));

    v1_con = np.dot(W1, x_con);
    y1_con = fun_Sigmoid(v1_con);

    v_con = np.dot(W2, y1_con);
    y_con_check[y_con_check.shape[0] - 1, k] = fun_Sigmoid(v_con);

plt.figure(2);
for k in range(num_point):
    if (y_con_check[y_con_check.shape[0] - 1, k] >= 0.5):
        plt.plot(x_c[x_c.shape[0] - 1, k], y_c[y_c.shape[0] - 1, k], 'b^');
    else:
        plt.plot(x_c[x_c.shape[0] - 1, k], y_c[y_c.shape[0] - 1, k], 'ks');

x_fun = np.linspace(0, 1, 100);
y_fun = np.float_power(x_fun, 2);
plt.plot(x_fun, y_fun, 'r');
plt.grid();
plt.show()




















