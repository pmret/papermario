.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242044_991824
/* 991824 80242044 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 991828 80242048 3C05FD05 */  lui       $a1, 0xfd05
/* 99182C 8024204C AFBF0010 */  sw        $ra, 0x10($sp)
/* 991830 80242050 0C0B1EAF */  jal       get_variable
/* 991834 80242054 34A50F8A */   ori      $a1, $a1, 0xf8a
/* 991838 80242058 24030001 */  addiu     $v1, $zero, 1
/* 99183C 8024205C AC430000 */  sw        $v1, ($v0)
/* 991840 80242060 8FBF0010 */  lw        $ra, 0x10($sp)
/* 991844 80242064 24020002 */  addiu     $v0, $zero, 2
/* 991848 80242068 03E00008 */  jr        $ra
/* 99184C 8024206C 27BD0018 */   addiu    $sp, $sp, 0x18
