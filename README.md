# Recursive Least Square

## Requirements

* QT 5.9
* Eigen3

## Algorithom (update)

* P Covariance matrix
* H regressor matrix
* theta parameter vector

```
psi_k_1 = (P*H) * (lambda + H.transpose()*P*H).inverse();
P_k_1 = P - ((P * H * H.transpose() *P) /(den +0.99)  );
theta_hat_k_1 = theta_hat + psi_k_1*(Y_k_1 - H.transpose()*theta_hat);
```
