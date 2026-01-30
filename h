function getTime() {
    const d = new Date();
    return d.getFullYear() + '-' +
        String(d.getMonth()+1).padStart(2,'0') + '-' +
        String(d.getDate()).padStart(2,'0') + ' ' +
        String(d.getHours()).padStart(2,'0') + ':' +
        String(d.getMinutes()).padStart(2,'0') + ':' +
        String(d.getSeconds()).padStart(2,'0');
}

function sendMessage(user) {
    const textarea = document.getElementById(user);
    const text = textarea.value;
    if (!text.trim()) return; // Не отправляем пустые
    
    textarea.value = '';

    const msg = document.createElement('div');
    msg.className = 'message ' + user;

    const content = document.createElement('div');
    content.textContent = text;

    const time = document.createElement('div');
    time.className = 'time';
    time.textContent = getTime();

    msg.appendChild(content);
    msg.appendChild(time);

    const chat = document.getElementById('chat');
    chat.prepend(msg);
}

function clearChat() {
    document.getElementById('chat').innerHTML = '';
}

function removeFirst() {
    const chat = document.getElementById('chat');
    if (chat.lastChild) chat.removeChild(chat.lastChild);
}

function removeLast() {
    const chat = document.getElementById('chat');
    if (chat.firstChild) chat.removeChild(chat.firstChild);
}

// Функция переключения темы
function toggleTheme() {
    document.body.classList.toggle('dark-theme');
}


:root {
    --bg-color: #f2f2f2;
    --container-bg: transparent;
    --text-color: #000;
    --chat-border: #999;
    --chat-bg: #fff;
    --btn-bg: #efefef;
}

/* Стили для темной темы */
body.dark-theme {
    --bg-color: #1a1a1a;
    --text-color: #ffffff;
    --chat-border: #444;
    --chat-bg: #2d2d2d;
    --btn-bg: #444;
}

* {
    box-sizing: border-box;
    font-family: Arial, sans-serif;
    transition: background 0.3s, color 0.3s; /* Плавный переход */
}

body {
    margin: 0;
    height: 100vh;
    display: flex;
    justify-content: center;
    align-items: center;
    background: var(--bg-color);
    color: var(--text-color);
}

.container {
    width: 90%;
    height: 90%;
    display: grid;
    grid-template-columns: 1fr 2fr 1fr;
    gap: 10px;
}

.controls {
    display: flex;
    flex-direction: column;
    gap: 10px;
}

textarea {
    resize: none;
    height: 120px;
    padding: 10px;
    font-size: 14px;
    background: var(--chat-bg);
    color: var(--text-color);
    border: 1px solid var(--chat-border);
}

button {
    padding: 8px;
    cursor: pointer;
    background: var(--btn-bg);
    color: var(--text-color);
    border: 1px solid var(--chat-border);
}

#chat {
    border: 1px solid var(--chat-border);
    background: var(--chat-bg);
    padding: 10px;
    overflow-y: auto;
    display: flex;
    flex-direction: column;
}

.message {
    margin-bottom: 10px;
    padding: 6px;
    border-radius: 5px;
}

.user1 {
    background: #4fa3ff;
    color: white;
}

.user2 {
    background: #ff4f7a;
    color: white;
}

.time {
    font-size: 11px;
    opacity: 0.8;
    margin-top: 4px;
}


<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <title>PR09 Мессенджер</title>
    <link rel="stylesheet" href="style.css">
    <script src="script.js" defer></script>
</head>
<body>
    <div class="container">
        <div class="controls left">
            <textarea id="user1" placeholder="Пользователь 1"></textarea>
            <button onclick="sendMessage('user1')">Отправить</button>
        </div>

        <div id="chat"></div>

        <div class="controls right">
            <textarea id="user2" placeholder="Пользователь 2"></textarea>
            <button onclick="sendMessage('user2')">Отправить</button>

            <button onclick="clearChat()">Очистить чат</button>
            <button onclick="removeFirst()">Удалить первое</button>
            <button onclick="removeLast()">Удалить последнее</button>
            <button id="theme-toggle" onclick="toggleTheme()">Сменить тему</button>
        </div>
    </div>
</body>
</html>






