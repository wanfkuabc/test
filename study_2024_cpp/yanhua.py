import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from scipy.spatial.distance import pdist, squareform

# 设置画布大小和背景颜色
fig, ax = plt.subplots(figsize=(8, 8), facecolor='black')

# 参数设置
N_PARTICLES = 100  # 粒子数量
MAX_HEIGHT = 500   # 烟花最大高度
PARTICLE_LIFE = 50  # 粒子生命周期
GRAVITY = 9.8      # 重力加速度

# 初始化粒子列表
particles = [{'position': (0, MAX_HEIGHT),
              'velocity': (np.random.uniform(-10, 10), 0),
              'age': 0,
              'max_age': np.random.randint(PARTICLE_LIFE, 2 * PARTICLE_LIFE)} for _ in range(N_PARTICLES)]

# 烟花爆炸函数
def firework_burst(particles):
    for particle in particles:
        particle['velocity'][1] -= GRAVITY  # 更新垂直速度（受重力影响）
        particle['position'] += particle['velocity']  # 更新粒子位置
        particle['age'] += 1  # 增加粒子年龄
        if particle['age'] > particle['max_age']:
            # 当粒子寿命结束时，重新初始化其位置和速度
            particle['position'] = (np.random.uniform(0, fig.get_figwidth()), MAX_HEIGHT)
            particle['velocity'] = (np.random.uniform(-10, 10), np.random.uniform(10, 30))
            particle['age'] = 0
            particle['max_age'] = np.random.randint(PARTICLE_LIFE, 2 * PARTICLE_LIFE)

# 绘制粒子函数
def draw_particles(ax, particles):
    ax.clear()  # 清除上一帧的画面
    ax.set_facecolor('black')  # 设置背景色
    for particle in particles:
        x, y = particle['position']
        ax.scatter(x, y, color='white', alpha=particle['age'] / particle['max_age'])  # 根据粒子年龄设置透明度
    ax.axis('off')  # 不显示坐标轴

# 创建动画
ani = FuncAnimation(fig, draw_particles, frames=None, fargs=(particles,), interval=20, blit=False, repeat=True)

# 添加烟花爆炸函数更新粒子状态
ani.event_source.add_callback(firework_burst, particles)

plt.show()