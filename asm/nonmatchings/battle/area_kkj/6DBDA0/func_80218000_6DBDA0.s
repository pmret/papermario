.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_6DBDA0
/* 6DBDA0 80218000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6DBDA4 80218004 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6DBDA8 80218008 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DBDAC 8021800C AFB00010 */  sw        $s0, 0x10($sp)
/* 6DBDB0 80218010 0C09A75B */  jal       get_actor
/* 6DBDB4 80218014 8C840148 */   lw       $a0, 0x148($a0)
/* 6DBDB8 80218018 3C108022 */  lui       $s0, %hi(D_802187E4)
/* 6DBDBC 8021801C 261087E4 */  addiu     $s0, $s0, %lo(D_802187E4)
/* 6DBDC0 80218020 8E030000 */  lw        $v1, ($s0)
/* 6DBDC4 80218024 0040882D */  daddu     $s1, $v0, $zero
/* 6DBDC8 80218028 24630009 */  addiu     $v1, $v1, 9
/* 6DBDCC 8021802C 44836000 */  mtc1      $v1, $f12
/* 6DBDD0 80218030 00000000 */  nop       
/* 6DBDD4 80218034 46806320 */  cvt.s.w   $f12, $f12
/* 6DBDD8 80218038 0C00A6C9 */  jal       clamp_angle
/* 6DBDDC 8021803C AE030000 */   sw       $v1, ($s0)
/* 6DBDE0 80218040 4600010D */  trunc.w.s $f4, $f0
/* 6DBDE4 80218044 44022000 */  mfc1      $v0, $f4
/* 6DBDE8 80218048 3C0140C9 */  lui       $at, 0x40c9
/* 6DBDEC 8021804C 34210FD0 */  ori       $at, $at, 0xfd0
/* 6DBDF0 80218050 44810000 */  mtc1      $at, $f0
/* 6DBDF4 80218054 44826000 */  mtc1      $v0, $f12
/* 6DBDF8 80218058 00000000 */  nop       
/* 6DBDFC 8021805C 46806320 */  cvt.s.w   $f12, $f12
/* 6DBE00 80218060 46006302 */  mul.s     $f12, $f12, $f0
/* 6DBE04 80218064 00000000 */  nop       
/* 6DBE08 80218068 3C0143B4 */  lui       $at, 0x43b4
/* 6DBE0C 8021806C 44810000 */  mtc1      $at, $f0
/* 6DBE10 80218070 AE020000 */  sw        $v0, ($s0)
/* 6DBE14 80218074 0C00A85B */  jal       sin_rad
/* 6DBE18 80218078 46006303 */   div.s    $f12, $f12, $f0
/* 6DBE1C 8021807C 3C014040 */  lui       $at, 0x4040
/* 6DBE20 80218080 44811000 */  mtc1      $at, $f2
/* 6DBE24 80218084 00000000 */  nop       
/* 6DBE28 80218088 46020002 */  mul.s     $f0, $f0, $f2
/* 6DBE2C 8021808C 00000000 */  nop       
/* 6DBE30 80218090 4600010D */  trunc.w.s $f4, $f0
/* 6DBE34 80218094 44032000 */  mfc1      $v1, $f4
/* 6DBE38 80218098 00000000 */  nop       
/* 6DBE3C 8021809C A223019A */  sb        $v1, 0x19a($s1)
/* 6DBE40 802180A0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6DBE44 802180A4 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DBE48 802180A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DBE4C 802180AC 24020002 */  addiu     $v0, $zero, 2
/* 6DBE50 802180B0 03E00008 */  jr        $ra
/* 6DBE54 802180B4 27BD0020 */   addiu    $sp, $sp, 0x20
