import pandas as pd

df1 = pd.read_csv('SampleData.csv', index_col='Date')
df2 = pd.read_csv('SampleData.csv', index_col='Date')
df3 = pd.read_csv('SampleData2.csv', index_col='Date')
df = pd.concat([df1,df2,df3],axis=1,join='outer')
print(df)
headers = df.columns.values
print(headers)
df.to_csv('output.csv',headers=headers)