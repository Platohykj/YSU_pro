import json
import os
from flask import Flask, jsonify, render_template, request, send_file
from flask_cors import CORS

app = Flask(__name__, template_folder='./templates')
CORS(app)


@app.route('/')
def index():
    return render_template('index.html')


@app.route('/signin', methods=['POST'])
def receive_json():
    # 检查请求是否包含 JSON 数据
    if request.is_json:
        # 获取 JSON 数据
        json_data = request.json
        # 处理 JSON 数据
        print(json_data)
        #检查是否有重复数据
        if os.path.exists('user.json'):
            with open('user.json', 'r') as f:
                data = json.load(f)
                for key in json_data:
                    if key in data:
                        return jsonify({'error': 'Data already exists'}), 400
        #读取文件
        with open('user.json', 'r') as f:
            data = json.load(f)
        #合并数据
        data.update(json_data)
        #写入文件
        with open('user.json', 'w') as f:
            #格式化输出
            json.dump(data, f, indent=4)
        # 返回一个 JSON 响应，表明数据已成功接收
        return jsonify({'message': 'JSON data received successfully'}),200
    else:
        # 如果请求不包含 JSON 数据，则返回错误响应
        return jsonify({'error': 'Request does not contain JSON data'}), 400

@app.route('/login', methods=['POST'])
def login():
    # 检查请求是否包含 JSON 数据
    if request.is_json:
        # 获取 JSON 数据
        json_data = request.json
        # 处理 JSON 数据
        print(json_data)
        #检查是否有重复数据
        if os.path.exists('user.json'):
            with open('user.json', 'r') as f:
                data = json.load(f)
                for key in json_data:
                    if key in data:
                        return jsonify({'message': 'Login successfully'}), 200
        return jsonify({'error': 'Data not exists'}), 400
    else:
        # 如果请求不包含 JSON 数据，则返回错误响应
        return jsonify({'error': 'Request does not contain JSON data'}), 400

@app.route('/student', methods=['POST'])
def student():
    if request.is_json:
        json_data = request.json
        print(json_data)
        print(type(json_data))
        with open('student.json', 'r') as f:
            data = json.load(f)
        data.extend(json_data)
        with open('student.json', 'w') as f:
            json.dump(data, f, indent=4)
        return jsonify({'message': 'JSON data received successfully'}), 200
    else:
        return jsonify({'error': 'Request does not contain JSON data'}), 400



@app.route('/teacher', methods=['POST'])
def teacher():
    if request.is_json:
        json_data = request.json
        print(json_data)
        print(type(json_data))
        with open('teacher.json', 'r') as f:
            data = json.load(f)
        data.extend(json_data)
        with open('teacher.json', 'w') as f:
            json.dump(data, f, indent=4)
        return jsonify({'message': 'JSON data received successfully'}), 200
    else:
        return jsonify({'error': 'Request does not contain JSON data'}), 400

@app.route('/search', methods=['POST'])
def search():

    #获取请求json数据
    if request.is_json:
        json_data = request.json

        isteacher = json_data['isteacher']
        select_data = []
        if isteacher == 1:
            with open('teacher.json', 'r') as f:
                data = json.load(f)
            #查找符合json数据的数据
            for i in data:
                for key in json_data:
                    if key in i:
                        if i[key] == json_data[key]:
                            select_data.append(i)
                            break
            #以表格形式输出到Temp.txt
            with open('Temp.txt', 'wb') as f:
                f.write('id\tname\tage\theight\tweight\tgender\tclass_num\tgrade\tscore\trank\tsalary\n'.encode('utf-8'))
                for i in select_data:
                    f.write((str(i['id'])+'\t'+i['name']+'\t'+str(i['age'])+'\t'+str(i['height'])+'\t'+str(i['weight'])+'\t'+str(i['gender'])+'\t'+str(i['class_num'])+'\t'+str(i['grade'])+'\t'+'0'+'\t'+'0'+'\t'+str(i['salary'])+'\n').encode('utf-8'))
            #返回Temp.txt文件
            return send_file('Temp.txt', as_attachment=False)
        else:
            with open('student.json', 'r') as f:
                data = json.load(f)
            #查找符合json数据的数据
            for i in data:
                for key in json_data:
                    if key in i:
                        if i[key] == json_data[key]:
                            select_data.append(i)
                            break
            #以表格形式输出到Temp.txt
            with open('Temp.txt', 'wb') as f:
                f.write('id\tname\tage\theight\tweight\tgender\tclass_num\tgrade\tscore\trank\tsalary\n'.encode('utf-8'))
                for i in select_data:
                    f.write((str(i['id'])+'\t'+i['name']+'\t'+str(i['age'])+'\t'+str(i['height'])+'\t'+str(i['weight'])+'\t'+str(i['gender'])+'\t'+str(i['class_num'])+'\t'+str(i['grade'])+'\t'+str(i['score'])+'\t'+str(i['rank'])+'\t'+'0'+'\n').encode('utf-8'))
            #返回Temp.txt文件
            return send_file('Temp.txt', as_attachment=False)

@app.route('/stat', methods=['POST'])
def stat():
    #统计学生和老师的人数
    with open('student.json', 'r') as f:
        student = json.load(f)
    with open('teacher.json', 'r') as f:
        teacher = json.load(f)
    total = len(student) + len(teacher)
    #以文本形式输出
    with open('Temp.txt', 'wb') as f:
        f.write((str(len(student))+'\t'+str(len(teacher))+'\t'+str(total)).encode('utf-8'))
    return send_file('Temp.txt', as_attachment=False)

@app.route('/delete', methods=['POST'])
def delete():
    if request.is_json:
        #获取请求json数据
        json_data = request.json
        print(json_data)
        #json_data中为id
        id = json_data['id']
        print(id)
        #将id转换为int
        id = int(id)
        print(id)
        # 读取 JSON 数据
        with open('student.json', 'r') as f:
            data = json.load(f)
            f.close()
            print(data)
        # 创建一个新列表，用于存储不含 id 为 1 的对象的数据
        filtered_data = [obj for obj in data if (obj['id'] != id and obj['name'] != "")]
        print(filtered_data)
        # 将筛选后的数据写入到文件中
        with open('student.json', 'w+') as f:
            json.dump(filtered_data, f, indent=4)
            f.close()

        with open('teacher.json', 'r') as f:
            data_t = json.load(f)
            f.close()
            print(data_t)
        # 创建一个新列表，用于存储不含 id 为 1 的对象的数据
        filtered_data = [obj for obj in data_t if (obj['id'] != id and obj['name'] != "")]
        print(filtered_data)
        # 将筛选后的数据写入到文件中
        with open('teacher.json', 'w+') as f:
            json.dump(filtered_data, f, indent=4)
            f.close()

        print("Data with id=1 removed successfully!")

        return jsonify({'message': 'Delete successfully'}), 200
    else:
        return jsonify({'error': 'Request does not contain id'}), 400


if __name__ == '__main__':
    app.run(host='0.0.0.0',debug=True, use_reloader=False)

