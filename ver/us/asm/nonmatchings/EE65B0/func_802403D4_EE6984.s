.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403D4_EE6984
/* EE6984 802403D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EE6988 802403D8 3C028011 */  lui       $v0, %hi(D_80117852)
/* EE698C 802403DC 80427852 */  lb        $v0, %lo(D_80117852)($v0)
/* EE6990 802403E0 0080182D */  daddu     $v1, $a0, $zero
/* EE6994 802403E4 1040000C */  beqz      $v0, .L80240418
/* EE6998 802403E8 AFBF0010 */   sw       $ra, 0x10($sp)
/* EE699C 802403EC 2404FFFC */  addiu     $a0, $zero, -4
/* EE69A0 802403F0 24020001 */  addiu     $v0, $zero, 1
/* EE69A4 802403F4 0C00F92F */  jal       dead_get_npc_unsafe
/* EE69A8 802403F8 AC6200BC */   sw       $v0, 0xbc($v1)
/* EE69AC 802403FC 0000202D */  daddu     $a0, $zero, $zero
/* EE69B0 80240400 3C05FD05 */  lui       $a1, 0xfd05
/* EE69B4 80240404 8C460000 */  lw        $a2, ($v0)
/* EE69B8 80240408 0C0B551A */  jal       dead_evt_set_variable
/* EE69BC 8024040C 34A50F80 */   ori      $a1, $a1, 0xf80
/* EE69C0 80240410 08090108 */  j         .L80240420
/* EE69C4 80240414 24020002 */   addiu    $v0, $zero, 2
.L80240418:
/* EE69C8 80240418 AC6000BC */  sw        $zero, 0xbc($v1)
/* EE69CC 8024041C 24020002 */  addiu     $v0, $zero, 2
.L80240420:
/* EE69D0 80240420 8FBF0010 */  lw        $ra, 0x10($sp)
/* EE69D4 80240424 03E00008 */  jr        $ra
/* EE69D8 80240428 27BD0018 */   addiu    $sp, $sp, 0x18
