.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_zone_enabled
/* EEB68 802CA1B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EEB6C 802CA1BC 000410C0 */  sll       $v0, $a0, 3
/* EEB70 802CA1C0 00441023 */  subu      $v0, $v0, $a0
/* EEB74 802CA1C4 3C03800E */  lui       $v1, %hi(D_800D91D4)
/* EEB78 802CA1C8 8C6391D4 */  lw        $v1, %lo(D_800D91D4)($v1)
/* EEB7C 802CA1CC 00021080 */  sll       $v0, $v0, 2
/* EEB80 802CA1D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* EEB84 802CA1D4 AFB10014 */  sw        $s1, 0x14($sp)
/* EEB88 802CA1D8 AFB00010 */  sw        $s0, 0x10($sp)
/* EEB8C 802CA1DC 00628021 */  addu      $s0, $v1, $v0
/* EEB90 802CA1E0 86040004 */  lh        $a0, 4($s0)
/* EEB94 802CA1E4 04800003 */  bltz      $a0, .L802CA1F4
/* EEB98 802CA1E8 00A0882D */   daddu    $s1, $a1, $zero
/* EEB9C 802CA1EC 0C0B286E */  jal       set_zone_enabled
/* EEBA0 802CA1F0 00000000 */   nop
.L802CA1F4:
/* EEBA4 802CA1F4 86040006 */  lh        $a0, 6($s0)
/* EEBA8 802CA1F8 04800003 */  bltz      $a0, .L802CA208
/* EEBAC 802CA1FC 00000000 */   nop
/* EEBB0 802CA200 0C0B286E */  jal       set_zone_enabled
/* EEBB4 802CA204 0220282D */   daddu    $a1, $s1, $zero
.L802CA208:
/* EEBB8 802CA208 12200006 */  beqz      $s1, .L802CA224
/* EEBBC 802CA20C 3C030001 */   lui      $v1, 1
/* EEBC0 802CA210 24020001 */  addiu     $v0, $zero, 1
/* EEBC4 802CA214 12220006 */  beq       $s1, $v0, .L802CA230
/* EEBC8 802CA218 3C03FFFE */   lui      $v1, 0xfffe
/* EEBCC 802CA21C 080B2890 */  j         .L802CA240
/* EEBD0 802CA220 00000000 */   nop
.L802CA224:
/* EEBD4 802CA224 8E020000 */  lw        $v0, ($s0)
/* EEBD8 802CA228 080B288F */  j         .L802CA23C
/* EEBDC 802CA22C 00431025 */   or       $v0, $v0, $v1
.L802CA230:
/* EEBE0 802CA230 8E020000 */  lw        $v0, ($s0)
/* EEBE4 802CA234 3463FFFF */  ori       $v1, $v1, 0xffff
/* EEBE8 802CA238 00431024 */  and       $v0, $v0, $v1
.L802CA23C:
/* EEBEC 802CA23C AE020000 */  sw        $v0, ($s0)
.L802CA240:
/* EEBF0 802CA240 8FBF0018 */  lw        $ra, 0x18($sp)
/* EEBF4 802CA244 8FB10014 */  lw        $s1, 0x14($sp)
/* EEBF8 802CA248 8FB00010 */  lw        $s0, 0x10($sp)
/* EEBFC 802CA24C 03E00008 */  jr        $ra
/* EEC00 802CA250 27BD0020 */   addiu    $sp, $sp, 0x20
