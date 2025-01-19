from setuptools import find_packages, setup

package_name = 'robo_navegacao'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='rasp',
    maintainer_email='rasp@todo.todo',
    description='Pacote de navegação para o robô assistente',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'navegacao = robo_navegacao.navegacao:main',
            'lidar = robo_navegacao.lidar:main',
        ],
    },
)

