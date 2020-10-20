.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403D4_CCB6E4
/* CCB6E4 802403D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CCB6E8 802403D8 3C028011 */  lui       $v0, 0x8011
/* CCB6EC 802403DC 8042F2A2 */  lb        $v0, -0xd5e($v0)
/* CCB6F0 802403E0 0080182D */  daddu     $v1, $a0, $zero
/* CCB6F4 802403E4 1040000C */  beqz      $v0, .L80240418
/* CCB6F8 802403E8 AFBF0010 */   sw       $ra, 0x10($sp)
/* CCB6FC 802403EC 2404FFFC */  addiu     $a0, $zero, -4
/* CCB700 802403F0 24020001 */  addiu     $v0, $zero, 1
/* CCB704 802403F4 0C00EABB */  jal       get_npc_unsafe
/* CCB708 802403F8 AC6200BC */   sw       $v0, 0xbc($v1)
/* CCB70C 802403FC 0000202D */  daddu     $a0, $zero, $zero
/* CCB710 80240400 3C05FD05 */  lui       $a1, 0xfd05
/* CCB714 80240404 8C460000 */  lw        $a2, ($v0)
/* CCB718 80240408 0C0B2026 */  jal       set_variable
/* CCB71C 8024040C 34A50F80 */   ori      $a1, $a1, 0xf80
/* CCB720 80240410 08090108 */  j         .L80240420
/* CCB724 80240414 24020002 */   addiu    $v0, $zero, 2
.L80240418:
/* CCB728 80240418 AC6000BC */  sw        $zero, 0xbc($v1)
/* CCB72C 8024041C 24020002 */  addiu     $v0, $zero, 2
.L80240420:
/* CCB730 80240420 8FBF0010 */  lw        $ra, 0x10($sp)
/* CCB734 80240424 03E00008 */  jr        $ra
/* CCB738 80240428 27BD0018 */   addiu    $sp, $sp, 0x18
