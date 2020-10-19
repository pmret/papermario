.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240224_BC44A4
/* BC44A4 80240224 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BC44A8 80240228 AFB00010 */  sw        $s0, 0x10($sp)
/* BC44AC 8024022C 0080802D */  daddu     $s0, $a0, $zero
/* BC44B0 80240230 AFBF0018 */  sw        $ra, 0x18($sp)
/* BC44B4 80240234 AFB10014 */  sw        $s1, 0x14($sp)
/* BC44B8 80240238 8E02000C */  lw        $v0, 0xc($s0)
/* BC44BC 8024023C 8C510000 */  lw        $s1, ($v0)
/* BC44C0 80240240 0C0B1EAF */  jal       get_variable
/* BC44C4 80240244 0220282D */   daddu    $a1, $s1, $zero
/* BC44C8 80240248 3C03FFF0 */  lui       $v1, 0xfff0
/* BC44CC 8024024C 3463FFFF */  ori       $v1, $v1, 0xffff
/* BC44D0 80240250 0200202D */  daddu     $a0, $s0, $zero
/* BC44D4 80240254 00431024 */  and       $v0, $v0, $v1
/* BC44D8 80240258 00021140 */  sll       $v0, $v0, 5
/* BC44DC 8024025C 3C068008 */  lui       $a2, %hi(gItemTable)
/* BC44E0 80240260 00C23021 */  addu      $a2, $a2, $v0
/* BC44E4 80240264 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* BC44E8 80240268 0C0B2026 */  jal       set_variable
/* BC44EC 8024026C 0220282D */   daddu    $a1, $s1, $zero
/* BC44F0 80240270 8FBF0018 */  lw        $ra, 0x18($sp)
/* BC44F4 80240274 8FB10014 */  lw        $s1, 0x14($sp)
/* BC44F8 80240278 8FB00010 */  lw        $s0, 0x10($sp)
/* BC44FC 8024027C 24020002 */  addiu     $v0, $zero, 2
/* BC4500 80240280 03E00008 */  jr        $ra
/* BC4504 80240284 27BD0020 */   addiu    $sp, $sp, 0x20
