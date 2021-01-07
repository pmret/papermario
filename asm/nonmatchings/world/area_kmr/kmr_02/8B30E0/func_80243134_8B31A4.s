.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243134_8B31A4
/* 8B31A4 80243134 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B31A8 80243138 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B31AC 8024313C 0080882D */  daddu     $s1, $a0, $zero
/* 8B31B0 80243140 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B31B4 80243144 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B31B8 80243148 8E30000C */  lw        $s0, 0xc($s1)
/* 8B31BC 8024314C 8E050000 */  lw        $a1, ($s0)
/* 8B31C0 80243150 0C0B1EAF */  jal       get_variable
/* 8B31C4 80243154 26100004 */   addiu    $s0, $s0, 4
/* 8B31C8 80243158 0220202D */  daddu     $a0, $s1, $zero
/* 8B31CC 8024315C 8E050000 */  lw        $a1, ($s0)
/* 8B31D0 80243160 0C0B1EAF */  jal       get_variable
/* 8B31D4 80243164 0040802D */   daddu    $s0, $v0, $zero
/* 8B31D8 80243168 44820000 */  mtc1      $v0, $f0
/* 8B31DC 8024316C 00000000 */  nop       
/* 8B31E0 80243170 46800020 */  cvt.s.w   $f0, $f0
/* 8B31E4 80243174 24020002 */  addiu     $v0, $zero, 2
/* 8B31E8 80243178 00501804 */  sllv      $v1, $s0, $v0
/* 8B31EC 8024317C 00701821 */  addu      $v1, $v1, $s0
/* 8B31F0 80243180 00431804 */  sllv      $v1, $v1, $v0
/* 8B31F4 80243184 00701823 */  subu      $v1, $v1, $s0
/* 8B31F8 80243188 000320C0 */  sll       $a0, $v1, 3
/* 8B31FC 8024318C 00641821 */  addu      $v1, $v1, $a0
/* 8B3200 80243190 000318C0 */  sll       $v1, $v1, 3
/* 8B3204 80243194 3C01800B */  lui       $at, %hi(D_800B1D98)
/* 8B3208 80243198 00230821 */  addu      $at, $at, $v1
/* 8B320C 8024319C E4201D98 */  swc1      $f0, %lo(D_800B1D98)($at)
/* 8B3210 802431A0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B3214 802431A4 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B3218 802431A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B321C 802431AC 03E00008 */  jr        $ra
/* 8B3220 802431B0 27BD0020 */   addiu    $sp, $sp, 0x20
