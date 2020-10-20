.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024037C
/* 8CAC7C 8024037C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8CAC80 80240380 AFB00010 */  sw        $s0, 0x10($sp)
/* 8CAC84 80240384 0080802D */  daddu     $s0, $a0, $zero
/* 8CAC88 80240388 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8CAC8C 8024038C AFB10014 */  sw        $s1, 0x14($sp)
/* 8CAC90 80240390 8E02000C */  lw        $v0, 0xc($s0)
/* 8CAC94 80240394 8C510000 */  lw        $s1, ($v0)
/* 8CAC98 80240398 0C0B1EAF */  jal       get_variable
/* 8CAC9C 8024039C 0220282D */   daddu    $a1, $s1, $zero
/* 8CACA0 802403A0 3C03FFF0 */  lui       $v1, 0xfff0
/* 8CACA4 802403A4 3463FFFF */  ori       $v1, $v1, 0xffff
/* 8CACA8 802403A8 0200202D */  daddu     $a0, $s0, $zero
/* 8CACAC 802403AC 00431024 */  and       $v0, $v0, $v1
/* 8CACB0 802403B0 00021140 */  sll       $v0, $v0, 5
/* 8CACB4 802403B4 3C068008 */  lui       $a2, %hi(gItemTable)
/* 8CACB8 802403B8 00C23021 */  addu      $a2, $a2, $v0
/* 8CACBC 802403BC 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 8CACC0 802403C0 0C0B2026 */  jal       set_variable
/* 8CACC4 802403C4 0220282D */   daddu    $a1, $s1, $zero
/* 8CACC8 802403C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8CACCC 802403CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 8CACD0 802403D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 8CACD4 802403D4 24020002 */  addiu     $v0, $zero, 2
/* 8CACD8 802403D8 03E00008 */  jr        $ra
/* 8CACDC 802403DC 27BD0020 */   addiu    $sp, $sp, 0x20
