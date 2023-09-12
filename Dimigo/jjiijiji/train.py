import numpy as np
import pandas as pd
from sklearn.preprocessing import MinMaxScaler
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, LSTM
from tensorflow.keras.optimizers import Adam

# 데이터 로딩 및 전처리
# 여기서는 데이터를 로드하는 코드가 필요합니다.

LOOKBACK = 60

# 데이터 정규화
scaler = MinMaxScaler(feature_range=(0, 1))
scaled_train = scaler.fit_transform(train)
scaled_test = scaler.transform(test)

# 훈련 및 테스트 데이터 준비
X_train, y_train = [], []
for i in range(LOOKBACK, len(scaled_train)):
    X_train.append(scaled_train[i-LOOKBACK:i, 0])
    y_train.append(scaled_train[i, 0])

X_test, y_test = [], []
for i in range(LOOKBACK, len(scaled_test)):
    X_test.append(scaled_test[i-LOOKBACK:i, 0])
    y_test.append(scaled_test[i, 0])

X_train, y_train = np.array(X_train), np.array(y_train)
X_test, y_test = np.array(X_test), np.array(y_test)
X_train = np.reshape(X_train, (X_train.shape[0], X_train.shape[1], 1))
X_test = np.reshape(X_test, (X_test.shape[0], X_test.shape[1], 1))

# LSTM 모델 구축
model = Sequential()
model.add(LSTM(units=50, return_sequences=True, input_shape=(X_train.shape[1], 1)))
model.add(LSTM(units=50))
model.add(Dense(units=1))

model.compile(optimizer=Adam(learning_rate=0.001), loss='mean_squared_error')
model.fit(X_train, y_train, epochs=100, batch_size=32, validation_data=(X_test, y_test))
