.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240134_ED4354
/* ED4354 80240134 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ED4358 80240138 AFB00010 */  sw        $s0, 0x10($sp)
/* ED435C 8024013C 0080802D */  daddu     $s0, $a0, $zero
/* ED4360 80240140 AFBF0018 */  sw        $ra, 0x18($sp)
/* ED4364 80240144 AFB10014 */  sw        $s1, 0x14($sp)
/* ED4368 80240148 8E02000C */  lw        $v0, 0xc($s0)
/* ED436C 8024014C 8C510000 */  lw        $s1, ($v0)
/* ED4370 80240150 0C0B53A3 */  jal       func_802D4E8C
/* ED4374 80240154 0220282D */   daddu    $a1, $s1, $zero
/* ED4378 80240158 3C03FFF0 */  lui       $v1, 0xfff0
/* ED437C 8024015C 3463FFFF */  ori       $v1, $v1, 0xffff
/* ED4380 80240160 0200202D */  daddu     $a0, $s0, $zero
/* ED4384 80240164 00431024 */  and       $v0, $v0, $v1
/* ED4388 80240168 00021140 */  sll       $v0, $v0, 5
/* ED438C 8024016C 3C068009 */  lui       $a2, %hi(D_8008D2C0)
/* ED4390 80240170 00C23021 */  addu      $a2, $a2, $v0
/* ED4394 80240174 8CC6D2C0 */  lw        $a2, %lo(D_8008D2C0)($a2)
/* ED4398 80240178 0C0B551A */  jal       func_802D5468
/* ED439C 8024017C 0220282D */   daddu    $a1, $s1, $zero
/* ED43A0 80240180 8FBF0018 */  lw        $ra, 0x18($sp)
/* ED43A4 80240184 8FB10014 */  lw        $s1, 0x14($sp)
/* ED43A8 80240188 8FB00010 */  lw        $s0, 0x10($sp)
/* ED43AC 8024018C 24020002 */  addiu     $v0, $zero, 2
/* ED43B0 80240190 03E00008 */  jr        $ra
/* ED43B4 80240194 27BD0020 */   addiu    $sp, $sp, 0x20
