.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_108_update
/* 3D68E8 E00D8128 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3D68EC E00D812C AFBF0010 */  sw        $ra, 0x10($sp)
/* 3D68F0 E00D8130 8C830000 */  lw        $v1, ($a0)
/* 3D68F4 E00D8134 8C85000C */  lw        $a1, 0xc($a0)
/* 3D68F8 E00D8138 30620010 */  andi      $v0, $v1, 0x10
/* 3D68FC E00D813C 10400005 */  beqz      $v0, .LE00D8154
/* 3D6900 E00D8140 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3D6904 E00D8144 00621024 */  and       $v0, $v1, $v0
/* 3D6908 E00D8148 AC820000 */  sw        $v0, ($a0)
/* 3D690C E00D814C 24020017 */  addiu     $v0, $zero, 0x17
/* 3D6910 E00D8150 ACA20010 */  sw        $v0, 0x10($a1)
.LE00D8154:
/* 3D6914 E00D8154 8CA30010 */  lw        $v1, 0x10($a1)
/* 3D6918 E00D8158 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3D691C E00D815C 10400002 */  beqz      $v0, .LE00D8168
/* 3D6920 E00D8160 2462FFFF */   addiu    $v0, $v1, -1
/* 3D6924 E00D8164 ACA20010 */  sw        $v0, 0x10($a1)
.LE00D8168:
/* 3D6928 E00D8168 8CA30014 */  lw        $v1, 0x14($a1)
/* 3D692C E00D816C 8CA60010 */  lw        $a2, 0x10($a1)
/* 3D6930 E00D8170 24620001 */  addiu     $v0, $v1, 1
/* 3D6934 E00D8174 04C10005 */  bgez      $a2, .LE00D818C
/* 3D6938 E00D8178 ACA20014 */   sw       $v0, 0x14($a1)
/* 3D693C E00D817C 0C080128 */  jal       shim_remove_effect
/* 3D6940 E00D8180 00000000 */   nop
/* 3D6944 E00D8184 08036094 */  j         .LE00D8250
/* 3D6948 E00D8188 00000000 */   nop
.LE00D818C:
/* 3D694C E00D818C 00C0202D */  daddu     $a0, $a2, $zero
/* 3D6950 E00D8190 C4A00018 */  lwc1      $f0, 0x18($a1)
/* 3D6954 E00D8194 28620017 */  slti      $v0, $v1, 0x17
/* 3D6958 E00D8198 ACA00028 */  sw        $zero, 0x28($a1)
/* 3D695C E00D819C ACA0002C */  sw        $zero, 0x2c($a1)
/* 3D6960 E00D81A0 1040000F */  beqz      $v0, .LE00D81E0
/* 3D6964 E00D81A4 E4A0001C */   swc1     $f0, 0x1c($a1)
/* 3D6968 E00D81A8 3C02E00E */  lui       $v0, %hi(D_E00D8818)
/* 3D696C E00D81AC 24428818 */  addiu     $v0, $v0, %lo(D_E00D8818)
/* 3D6970 E00D81B0 00031880 */  sll       $v1, $v1, 2
/* 3D6974 E00D81B4 00621821 */  addu      $v1, $v1, $v0
/* 3D6978 E00D81B8 84620000 */  lh        $v0, ($v1)
/* 3D697C E00D81BC 44820000 */  mtc1      $v0, $f0
/* 3D6980 E00D81C0 00000000 */  nop
/* 3D6984 E00D81C4 46800020 */  cvt.s.w   $f0, $f0
/* 3D6988 E00D81C8 E4A00030 */  swc1      $f0, 0x30($a1)
/* 3D698C E00D81CC 90620002 */  lbu       $v0, 2($v1)
/* 3D6990 E00D81D0 A0A20034 */  sb        $v0, 0x34($a1)
/* 3D6994 E00D81D4 90620003 */  lbu       $v0, 3($v1)
/* 3D6998 E00D81D8 08036085 */  j         .LE00D8214
/* 3D699C E00D81DC A0A20035 */   sb       $v0, 0x35($a1)
.LE00D81E0:
/* 3D69A0 E00D81E0 3C03E00E */  lui       $v1, %hi(D_E00D8818)
/* 3D69A4 E00D81E4 24638818 */  addiu     $v1, $v1, %lo(D_E00D8818)
/* 3D69A8 E00D81E8 84620058 */  lh        $v0, 0x58($v1)
/* 3D69AC E00D81EC 44820000 */  mtc1      $v0, $f0
/* 3D69B0 E00D81F0 00000000 */  nop
/* 3D69B4 E00D81F4 46800020 */  cvt.s.w   $f0, $f0
/* 3D69B8 E00D81F8 E4A00030 */  swc1      $f0, 0x30($a1)
/* 3D69BC E00D81FC 9062005A */  lbu       $v0, 0x5a($v1)
/* 3D69C0 E00D8200 A0A20034 */  sb        $v0, 0x34($a1)
/* 3D69C4 E00D8204 9063005B */  lbu       $v1, 0x5b($v1)
/* 3D69C8 E00D8208 24020018 */  addiu     $v0, $zero, 0x18
/* 3D69CC E00D820C ACA20014 */  sw        $v0, 0x14($a1)
/* 3D69D0 E00D8210 A0A30035 */  sb        $v1, 0x35($a1)
.LE00D8214:
/* 3D69D4 E00D8214 28820017 */  slti      $v0, $a0, 0x17
/* 3D69D8 E00D8218 1040000D */  beqz      $v0, .LE00D8250
/* 3D69DC E00D821C 00041880 */   sll      $v1, $a0, 2
/* 3D69E0 E00D8220 3C02E00E */  lui       $v0, %hi(D_E00D8818)
/* 3D69E4 E00D8224 24428818 */  addiu     $v0, $v0, %lo(D_E00D8818)
/* 3D69E8 E00D8228 00621821 */  addu      $v1, $v1, $v0
/* 3D69EC E00D822C 84620000 */  lh        $v0, ($v1)
/* 3D69F0 E00D8230 44820000 */  mtc1      $v0, $f0
/* 3D69F4 E00D8234 00000000 */  nop
/* 3D69F8 E00D8238 46800020 */  cvt.s.w   $f0, $f0
/* 3D69FC E00D823C E4A00030 */  swc1      $f0, 0x30($a1)
/* 3D6A00 E00D8240 90620002 */  lbu       $v0, 2($v1)
/* 3D6A04 E00D8244 A0A20034 */  sb        $v0, 0x34($a1)
/* 3D6A08 E00D8248 90620003 */  lbu       $v0, 3($v1)
/* 3D6A0C E00D824C A0A20035 */  sb        $v0, 0x35($a1)
.LE00D8250:
/* 3D6A10 E00D8250 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3D6A14 E00D8254 03E00008 */  jr        $ra
/* 3D6A18 E00D8258 27BD0018 */   addiu    $sp, $sp, 0x18
