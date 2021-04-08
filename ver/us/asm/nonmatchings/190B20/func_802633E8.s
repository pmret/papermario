.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802633E8
/* 191CC8 802633E8 0000282D */  daddu     $a1, $zero, $zero
/* 191CCC 802633EC 00A0202D */  daddu     $a0, $a1, $zero
/* 191CD0 802633F0 3C060040 */  lui       $a2, 0x40
/* 191CD4 802633F4 34C64000 */  ori       $a2, $a2, 0x4000
/* 191CD8 802633F8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 191CDC 802633FC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
.L80263400:
/* 191CE0 80263400 8C6200E0 */  lw        $v0, 0xe0($v1)
/* 191CE4 80263404 50400006 */  beql      $v0, $zero, .L80263420
/* 191CE8 80263408 24840001 */   addiu    $a0, $a0, 1
/* 191CEC 8026340C 8C420000 */  lw        $v0, ($v0)
/* 191CF0 80263410 00461024 */  and       $v0, $v0, $a2
/* 191CF4 80263414 50400001 */  beql      $v0, $zero, .L8026341C
/* 191CF8 80263418 24050001 */   addiu    $a1, $zero, 1
.L8026341C:
/* 191CFC 8026341C 24840001 */  addiu     $a0, $a0, 1
.L80263420:
/* 191D00 80263420 28820018 */  slti      $v0, $a0, 0x18
/* 191D04 80263424 1440FFF6 */  bnez      $v0, .L80263400
/* 191D08 80263428 24630004 */   addiu    $v1, $v1, 4
/* 191D0C 8026342C 03E00008 */  jr        $ra
/* 191D10 80263430 38A20001 */   xori     $v0, $a1, 1
