#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <string>
#include <vector>

class TreeNode {
private:
    std::string type;
    std::string value;
    std::vector<TreeNode*> children;

public:
    TreeNode(const std::string& type, const std::string& value = "") 
        : type(type), value(value) {}

    static TreeNode* createNonTerminalNode(const std::string& type) {
        return new TreeNode(type);
    }

    static TreeNode* createTerminalNode(const std::string& type, const std::string& value = "") {
        return new TreeNode(type, value);
    }

    void addChild(TreeNode* child) {
        children.push_back(child);
    }

    const std::string& getType() const {
        return type;
    }

    const std::string& getValue() const {
        return value;
    }

    const std::vector<TreeNode*>& getChildren() const {
        return children;
    }

    int getNumChildren() const {
        return children.size();
    }

void postOrderTraversal(std::ofstream& outFile, int indentation = 0) {
    if (!value.empty()) {
        for (int i = 0; i < indentation; ++i) {
            outFile << " ";
        }

        outFile << value;

        if (value == "{" || value == ";") {
            outFile << "\n";
           
            if (value == "{") {
                indentation += 4;
            } else {
                indentation = 0;
            }
            for (int i = 0; i < indentation; ++i) {
                outFile << " ";
            }
        } else {
            outFile << " ";
        }
    }

    for (auto child : children) {
        
        if (value == "{") {
            child->postOrderTraversal(outFile, indentation + 4);
        } else {
            child->postOrderTraversal(outFile, indentation);
        }
    }
}


    ~TreeNode() {
        for (auto child : children) {
            delete child;
        }
    }
};

#endif  // TREE_NODE_H
