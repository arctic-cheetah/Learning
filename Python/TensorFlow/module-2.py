import tensorflow as tf
print(tf.version)

t = tf.zeros([4, 4, 4])
print(t)
t = tf.reshape(t, [4, -1])
print(t)