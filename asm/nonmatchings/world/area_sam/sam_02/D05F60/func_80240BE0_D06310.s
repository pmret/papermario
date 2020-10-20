.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BE0_D06310
/* D06310 80240BE0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D06314 80240BE4 AFB00010 */  sw        $s0, 0x10($sp)
/* D06318 80240BE8 0080802D */  daddu     $s0, $a0, $zero
/* D0631C 80240BEC AFBF0018 */  sw        $ra, 0x18($sp)
/* D06320 80240BF0 AFB10014 */  sw        $s1, 0x14($sp)
/* D06324 80240BF4 8E02000C */  lw        $v0, 0xc($s0)
/* D06328 80240BF8 8C510000 */  lw        $s1, ($v0)
/* D0632C 80240BFC 0C0B1EAF */  jal       get_variable
/* D06330 80240C00 0220282D */   daddu    $a1, $s1, $zero
/* D06334 80240C04 3C03FFF0 */  lui       $v1, 0xfff0
/* D06338 80240C08 3463FFFF */  ori       $v1, $v1, 0xffff
/* D0633C 80240C0C 0200202D */  daddu     $a0, $s0, $zero
/* D06340 80240C10 00431024 */  and       $v0, $v0, $v1
/* D06344 80240C14 00021140 */  sll       $v0, $v0, 5
/* D06348 80240C18 3C068008 */  lui       $a2, %hi(gItemTable)
/* D0634C 80240C1C 00C23021 */  addu      $a2, $a2, $v0
/* D06350 80240C20 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* D06354 80240C24 0C0B2026 */  jal       set_variable
/* D06358 80240C28 0220282D */   daddu    $a1, $s1, $zero
/* D0635C 80240C2C 8FBF0018 */  lw        $ra, 0x18($sp)
/* D06360 80240C30 8FB10014 */  lw        $s1, 0x14($sp)
/* D06364 80240C34 8FB00010 */  lw        $s0, 0x10($sp)
/* D06368 80240C38 24020002 */  addiu     $v0, $zero, 2
/* D0636C 80240C3C 03E00008 */  jr        $ra
/* D06370 80240C40 27BD0020 */   addiu    $sp, $sp, 0x20
