.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240924_DB8234
/* DB8234 80240924 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DB8238 80240928 AFB00010 */  sw        $s0, 0x10($sp)
/* DB823C 8024092C 0080802D */  daddu     $s0, $a0, $zero
/* DB8240 80240930 AFBF0018 */  sw        $ra, 0x18($sp)
/* DB8244 80240934 AFB10014 */  sw        $s1, 0x14($sp)
/* DB8248 80240938 8E02000C */  lw        $v0, 0xc($s0)
/* DB824C 8024093C 8C510000 */  lw        $s1, ($v0)
/* DB8250 80240940 0C0B1EAF */  jal       get_variable
/* DB8254 80240944 0220282D */   daddu    $a1, $s1, $zero
/* DB8258 80240948 3C03FFF0 */  lui       $v1, 0xfff0
/* DB825C 8024094C 3463FFFF */  ori       $v1, $v1, 0xffff
/* DB8260 80240950 0200202D */  daddu     $a0, $s0, $zero
/* DB8264 80240954 00431024 */  and       $v0, $v0, $v1
/* DB8268 80240958 00021140 */  sll       $v0, $v0, 5
/* DB826C 8024095C 3C068008 */  lui       $a2, %hi(gItemTable)
/* DB8270 80240960 00C23021 */  addu      $a2, $a2, $v0
/* DB8274 80240964 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* DB8278 80240968 0C0B2026 */  jal       set_variable
/* DB827C 8024096C 0220282D */   daddu    $a1, $s1, $zero
/* DB8280 80240970 8FBF0018 */  lw        $ra, 0x18($sp)
/* DB8284 80240974 8FB10014 */  lw        $s1, 0x14($sp)
/* DB8288 80240978 8FB00010 */  lw        $s0, 0x10($sp)
/* DB828C 8024097C 24020002 */  addiu     $v0, $zero, 2
/* DB8290 80240980 03E00008 */  jr        $ra
/* DB8294 80240984 27BD0020 */   addiu    $sp, $sp, 0x20
