# Инструкция для запуска и сборки
1. Для начала необходимо выбрать директорию, в которую будет склонирован репозиторий. Склонировать данный репозиторий нужно введя следующую команду в терминале:

   ```
   git clone https://github.com/ssergl/yadro-lab-test.git
   ```
   В результате будет создана папка ***yadro-lab-test*** со всеми необходимыми файлами.

2. После этого нужно перейти в папку ***yadro-lab-test*** и осуществить сборку docker образа с помощью команды:

   ```
   docker build -t test:new .
   ```
   Таким образом, будет собран docker образ в текущей директории, которому присвоено имя ***test*** и тэг ***new***.
   Пример сборки представлен ниже.
   
  <div align="center">
  <img src="https://github.com/ssergl/yadro-lab/blob/main/images/build1.png?raw=true" width="80%" height="80%" style="margin-bottom: 10px; margin-top: 10px;">
</div>

<br>

<div align="center">
  <img src="https://github.com/ssergl/yadro-lab/blob/main/images/build2.png?raw=true" width="80%" height="80%" style="margin-bottom: 10px; margin-top: 10px;">
</div>

<br>

<div align="center">
  <img src="https://github.com/ssergl/yadro-lab/blob/main/images/build3.png?raw=true" width="70%" height="70%" style="margin-bottom: 10px; margin-top: 10px;">
</div>


3. Теперь необходимо запустить контейнер из собранного на предыдущем шаге образа командой:

   ```
   docker run --rm test:new
   ```
   Флаг *--rm* нужен для того, чтобы удалить контейнер после его завершения. Наличие этого флага в команде выше необязательно.
   Получаем результат как на скриншоте ниже.

   <div align="center">
   <img src="https://github.com/ssergl/yadro-lab/blob/main/images/docker_run.png?raw=true" >
   </div>
