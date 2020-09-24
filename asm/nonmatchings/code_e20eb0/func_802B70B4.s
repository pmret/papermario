.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B70B4
/* E20F64 802B70B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E20F68 802B70B8 AFB00010 */  sw        $s0, 0x10($sp)
/* E20F6C 802B70BC 3C10802B */  lui       $s0, 0x802b
/* E20F70 802B70C0 261079A8 */  addiu     $s0, $s0, 0x79a8
/* E20F74 802B70C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* E20F78 802B70C8 8E040000 */  lw        $a0, ($s0)
/* E20F7C 802B70CC 0C00A580 */  jal       mem_clear
/* E20F80 802B70D0 2405002C */   addiu    $a1, $zero, 0x2c
/* E20F84 802B70D4 3C058011 */  lui       $a1, 0x8011
/* E20F88 802B70D8 24A5EFC8 */  addiu     $a1, $a1, -0x1038
/* E20F8C 802B70DC 8CA400C8 */  lw        $a0, 0xc8($a1)
/* E20F90 802B70E0 8E020000 */  lw        $v0, ($s0)
/* E20F94 802B70E4 AC440000 */  sw        $a0, ($v0)
/* E20F98 802B70E8 848300A8 */  lh        $v1, 0xa8($a0)
/* E20F9C 802B70EC C480003C */  lwc1      $f0, 0x3c($a0)
/* E20FA0 802B70F0 44831000 */  mtc1      $v1, $f2
/* E20FA4 802B70F4 00000000 */  nop       
/* E20FA8 802B70F8 468010A0 */  cvt.s.w   $f2, $f2
/* E20FAC 802B70FC 46020000 */  add.s     $f0, $f0, $f2
/* E20FB0 802B7100 3C014100 */  lui       $at, 0x4100
/* E20FB4 802B7104 44811000 */  mtc1      $at, $f2
/* E20FB8 802B7108 00000000 */  nop       
/* E20FBC 802B710C 46020000 */  add.s     $f0, $f0, $f2
/* E20FC0 802B7110 E440001C */  swc1      $f0, 0x1c($v0)
/* E20FC4 802B7114 E4400008 */  swc1      $f0, 8($v0)
/* E20FC8 802B7118 C4800038 */  lwc1      $f0, 0x38($a0)
/* E20FCC 802B711C E4400004 */  swc1      $f0, 4($v0)
/* E20FD0 802B7120 C4820040 */  lwc1      $f2, 0x40($a0)
/* E20FD4 802B7124 A040002A */  sb        $zero, 0x2a($v0)
/* E20FD8 802B7128 8E040000 */  lw        $a0, ($s0)
/* E20FDC 802B712C 3C013DCC */  lui       $at, 0x3dcc
/* E20FE0 802B7130 3421CCCD */  ori       $at, $at, 0xcccd
/* E20FE4 802B7134 44810000 */  mtc1      $at, $f0
/* E20FE8 802B7138 3C03802B */  lui       $v1, 0x802b
/* E20FEC 802B713C 2463742C */  addiu     $v1, $v1, 0x742c
/* E20FF0 802B7140 AC400018 */  sw        $zero, 0x18($v0)
/* E20FF4 802B7144 3C018011 */  lui       $at, 0x8011
/* E20FF8 802B7148 AC23C940 */  sw        $v1, -0x36c0($at)
/* E20FFC 802B714C E442000C */  swc1      $f2, 0xc($v0)
/* E21000 802B7150 E4800014 */  swc1      $f0, 0x14($a0)
/* E21004 802B7154 8CA20004 */  lw        $v0, 4($a1)
/* E21008 802B7158 3C013ECC */  lui       $at, 0x3ecc
/* E2100C 802B715C 3421CCCD */  ori       $at, $at, 0xcccd
/* E21010 802B7160 44810000 */  mtc1      $at, $f0
/* E21014 802B7164 34420020 */  ori       $v0, $v0, 0x20
/* E21018 802B7168 ACA20004 */  sw        $v0, 4($a1)
/* E2101C 802B716C A080002A */  sb        $zero, 0x2a($a0)
/* E21020 802B7170 3C038007 */  lui       $v1, 0x8007
/* E21024 802B7174 8C637410 */  lw        $v1, 0x7410($v1)
/* E21028 802B7178 E4800014 */  swc1      $f0, 0x14($a0)
/* E2102C 802B717C 00031080 */  sll       $v0, $v1, 2
/* E21030 802B7180 00431021 */  addu      $v0, $v0, $v1
/* E21034 802B7184 00021080 */  sll       $v0, $v0, 2
/* E21038 802B7188 00431023 */  subu      $v0, $v0, $v1
/* E2103C 802B718C 000218C0 */  sll       $v1, $v0, 3
/* E21040 802B7190 00431021 */  addu      $v0, $v0, $v1
/* E21044 802B7194 000210C0 */  sll       $v0, $v0, 3
/* E21048 802B7198 3C01800B */  lui       $at, 0x800b
/* E2104C 802B719C 00220821 */  addu      $at, $at, $v0
/* E21050 802B71A0 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* E21054 802B71A4 240200FF */  addiu     $v0, $zero, 0xff
/* E21058 802B71A8 8E030000 */  lw        $v1, ($s0)
/* E2105C 802B71AC 46000007 */  neg.s     $f0, $f0
/* E21060 802B71B0 A062002B */  sb        $v0, 0x2b($v1)
/* E21064 802B71B4 E4600010 */  swc1      $f0, 0x10($v1)
/* E21068 802B71B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2106C 802B71BC 8FB00010 */  lw        $s0, 0x10($sp)
/* E21070 802B71C0 03E00008 */  jr        $ra
/* E21074 802B71C4 27BD0018 */   addiu    $sp, $sp, 0x18
