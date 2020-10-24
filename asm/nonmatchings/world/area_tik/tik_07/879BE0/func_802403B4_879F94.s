.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403B4_879F94
/* 879F94 802403B4 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 879F98 802403B8 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 879F9C 802403BC 000420C0 */  sll       $a0, $a0, 3
/* 879FA0 802403C0 00822021 */  addu      $a0, $a0, $v0
/* 879FA4 802403C4 90820014 */  lbu       $v0, 0x14($a0)
/* 879FA8 802403C8 10400009 */  beqz      $v0, .L802403F0
/* 879FAC 802403CC 00000000 */   nop      
/* 879FB0 802403D0 90820015 */  lbu       $v0, 0x15($a0)
/* 879FB4 802403D4 00022600 */  sll       $a0, $v0, 0x18
/* 879FB8 802403D8 00041E03 */  sra       $v1, $a0, 0x18
/* 879FBC 802403DC 00051400 */  sll       $v0, $a1, 0x10
/* 879FC0 802403E0 00021403 */  sra       $v0, $v0, 0x10
/* 879FC4 802403E4 0043102A */  slt       $v0, $v0, $v1
/* 879FC8 802403E8 10400003 */  beqz      $v0, .L802403F8
/* 879FCC 802403EC 00000000 */   nop      
.L802403F0:
/* 879FD0 802403F0 03E00008 */  jr        $ra
/* 879FD4 802403F4 2402FFFF */   addiu    $v0, $zero, -1
.L802403F8:
/* 879FD8 802403F8 03E00008 */  jr        $ra
/* 879FDC 802403FC 00041603 */   sra      $v0, $a0, 0x18
