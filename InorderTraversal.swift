import Foundation

/**
 * Definition for a binary tree node
 *
 * class TreeNode {
 *    var val: Int = 0
 *    var left: TreeNode?
 *    var right: TreeNode?
 * }
 *
 */

class Solution {
	func inorderTraversal(_ A: TreeNode?) -> [Int] {
        var stack = [TreeNode]()
        var result = [Int]()
        var node = A
        
        while(node != nil || !stack.isEmpty) {
            
            while(node != nil) {
                stack.append(node!)
                node = node!.left
            }
            node = stack.removeLast()
            result.append(node!.val)
            node = node!.right
        }
        
        return result
	}
}
