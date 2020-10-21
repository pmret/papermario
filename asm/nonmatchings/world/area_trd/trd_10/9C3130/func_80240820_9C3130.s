.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240820_9C3130
/* 9C3130 80240820 3C038011 */  lui       $v1, 0x8011
/* 9C3134 80240824 8063F2A2 */  lb        $v1, -0xd5e($v1)
/* 9C3138 80240828 24020003 */  addiu     $v0, $zero, 3
/* 9C313C 8024082C 54620003 */  bnel      $v1, $v0, .L8024083C
/* 9C3140 80240830 AC800084 */   sw       $zero, 0x84($a0)
/* 9C3144 80240834 24020001 */  addiu     $v0, $zero, 1
/* 9C3148 80240838 AC820084 */  sw        $v0, 0x84($a0)
.L8024083C:
/* 9C314C 8024083C 03E00008 */  jr        $ra
/* 9C3150 80240840 24020002 */   addiu    $v0, $zero, 2
/* 9C3154 80240844 00000000 */  nop       
/* 9C3158 80240848 00000000 */  nop       
/* 9C315C 8024084C 00000000 */  nop       
