.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_9867D0
/* 9867D0 802402F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9867D4 802402F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9867D8 802402F8 8C82000C */  lw        $v0, 0xc($a0)
/* 9867DC 802402FC 0C0B1EAF */  jal       get_variable
/* 9867E0 80240300 8C450000 */   lw       $a1, ($v0)
/* 9867E4 80240304 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* 9867E8 80240308 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* 9867EC 8024030C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9867F0 80240310 00621826 */  xor       $v1, $v1, $v0
/* 9867F4 80240314 0003182B */  sltu      $v1, $zero, $v1
/* 9867F8 80240318 00031040 */  sll       $v0, $v1, 1
/* 9867FC 8024031C 03E00008 */  jr        $ra
/* 986800 80240320 27BD0018 */   addiu    $sp, $sp, 0x18
/* 986804 80240324 00000000 */  nop       
/* 986808 80240328 00000000 */  nop       
/* 98680C 8024032C 00000000 */  nop       
