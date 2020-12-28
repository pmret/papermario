.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_4CF1B0
/* 4CF1B0 80218000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4CF1B4 80218004 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4CF1B8 80218008 AFB10014 */  sw        $s1, 0x14($sp)
/* 4CF1BC 8021800C AFB00010 */  sw        $s0, 0x10($sp)
/* 4CF1C0 80218010 8C840148 */  lw        $a0, 0x148($a0)
/* 4CF1C4 80218014 0C09A75B */  jal       get_actor
/* 4CF1C8 80218018 00A0802D */   daddu    $s0, $a1, $zero
/* 4CF1CC 8021801C 12000003 */  beqz      $s0, .L8021802C
/* 4CF1D0 80218020 0040882D */   daddu    $s1, $v0, $zero
/* 4CF1D4 80218024 3C018022 */  lui       $at, %hi(D_80219040)
/* 4CF1D8 80218028 AC209040 */  sw        $zero, %lo(D_80219040)($at)
.L8021802C:
/* 4CF1DC 8021802C 3C108022 */  lui       $s0, %hi(D_80219040)
/* 4CF1E0 80218030 26109040 */  addiu     $s0, $s0, %lo(D_80219040)
/* 4CF1E4 80218034 8E020000 */  lw        $v0, ($s0)
/* 4CF1E8 80218038 2442000F */  addiu     $v0, $v0, 0xf
/* 4CF1EC 8021803C 44826000 */  mtc1      $v0, $f12
/* 4CF1F0 80218040 00000000 */  nop       
/* 4CF1F4 80218044 46806320 */  cvt.s.w   $f12, $f12
/* 4CF1F8 80218048 0C00A6C9 */  jal       clamp_angle
/* 4CF1FC 8021804C AE020000 */   sw       $v0, ($s0)
/* 4CF200 80218050 4600010D */  trunc.w.s $f4, $f0
/* 4CF204 80218054 44022000 */  mfc1      $v0, $f4
/* 4CF208 80218058 3C0140C9 */  lui       $at, 0x40c9
/* 4CF20C 8021805C 34210FD0 */  ori       $at, $at, 0xfd0
/* 4CF210 80218060 44810000 */  mtc1      $at, $f0
/* 4CF214 80218064 44826000 */  mtc1      $v0, $f12
/* 4CF218 80218068 00000000 */  nop       
/* 4CF21C 8021806C 46806320 */  cvt.s.w   $f12, $f12
/* 4CF220 80218070 46006302 */  mul.s     $f12, $f12, $f0
/* 4CF224 80218074 00000000 */  nop       
/* 4CF228 80218078 3C0143B4 */  lui       $at, 0x43b4
/* 4CF22C 8021807C 44810000 */  mtc1      $at, $f0
/* 4CF230 80218080 AE020000 */  sw        $v0, ($s0)
/* 4CF234 80218084 0C00A85B */  jal       sin_rad
/* 4CF238 80218088 46006303 */   div.s    $f12, $f12, $f0
/* 4CF23C 8021808C 3C014040 */  lui       $at, 0x4040
/* 4CF240 80218090 44811000 */  mtc1      $at, $f2
/* 4CF244 80218094 00000000 */  nop       
/* 4CF248 80218098 46020002 */  mul.s     $f0, $f0, $f2
/* 4CF24C 8021809C 00000000 */  nop       
/* 4CF250 802180A0 4600010D */  trunc.w.s $f4, $f0
/* 4CF254 802180A4 44032000 */  mfc1      $v1, $f4
/* 4CF258 802180A8 00000000 */  nop       
/* 4CF25C 802180AC A223019A */  sb        $v1, 0x19a($s1)
/* 4CF260 802180B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4CF264 802180B4 8FB10014 */  lw        $s1, 0x14($sp)
/* 4CF268 802180B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 4CF26C 802180BC 0000102D */  daddu     $v0, $zero, $zero
/* 4CF270 802180C0 03E00008 */  jr        $ra
/* 4CF274 802180C4 27BD0020 */   addiu    $sp, $sp, 0x20
