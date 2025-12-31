# DSreview

**Data Structures: Comprehensive notes & C++ implementations**

本项目是我对数据结构课程内容的梳理与实战实现。采用文档与代码分离的结构，用于期末复习。

## 📂 目录结构 (Repository Structure)

```text
/DSreview
│  README.md                
│  LICENSE                  
│  .gitignore              
│
├─Docs                      # 知识梳理文档 (Markdown)
│     
└─Src                       # 源代码核心区 (C++)
```

## 🔍 题目查找方式 (How to Find Problems)

若需查找具体题目的实现代码，请参考以下步骤：

1. **查看文档**：进入 `Docs/` 文件夹打开对应章节的 Markdown 文档。
2. **定位索引**：在文档最下方的 **“题目索引”** 栏目中找到题目名称及其对应的源代码文件名。
3. **获取源码**：根据文件名进入 `Src/` 对应章节的文件夹中即可找到该 `.cpp` 实现文件。

## 🚀 编译与运行指引

本项目中的每个 `.cpp` 文件（如 `Infix2Postfix.cpp`, `Evaluate.cpp` 等）均包含独立的 `main` 函数，可作为独立的工具运行。由于文件间共享 `stackModel.h`，请根据以下方式进行编译：

#### 方式一：命令行单文件编译（推荐）

如果你安装了 Visual Studio，建议使用 **Developer PowerShell for VS**，这是最轻便的方法：

1. **打开终端**：在 VS 中按 `Ctrl +` 或搜索 "Developer PowerShell"。

2. **编译指定文件**：

```PowerShell
# 编译中缀转后缀工具
cl /EHsc Infix2Postfix.cpp 
```

3. **运行程序**：

```PowerShell
   .\Infix2Postfix.exe
```

4.**清理编译文件**

```PowerShell
rm *.obj,*.exe
```

#### 方式二：集成开发环境 (IDE)

如果你习惯直接点击 VS 的“运行”按钮：

1. **新建项目**：为每个任务创建一个新的“空项目”。

2. **添加文件**：将对应的 `.cpp` 文件和 `stackModel.h` 复制/导入到该项目中。

3. **注意**：请勿在一个项目中同时放置多个包含 `main` 函数的 `.cpp` 文件，否则会导致链接错误（LNK2005）。
