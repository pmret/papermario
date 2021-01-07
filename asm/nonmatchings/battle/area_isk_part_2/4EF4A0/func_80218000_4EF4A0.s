.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_4EF4A0
/* 4EF4A0 80218000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 4EF4A4 80218004 AFB40020 */  sw        $s4, 0x20($sp)
/* 4EF4A8 80218008 24140003 */  addiu     $s4, $zero, 3
/* 4EF4AC 8021800C AFB20018 */  sw        $s2, 0x18($sp)
/* 4EF4B0 80218010 AFBF0024 */  sw        $ra, 0x24($sp)
/* 4EF4B4 80218014 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4EF4B8 80218018 AFB10014 */  sw        $s1, 0x14($sp)
/* 4EF4BC 8021801C AFB00010 */  sw        $s0, 0x10($sp)
/* 4EF4C0 80218020 F7BE0050 */  sdc1      $f30, 0x50($sp)
/* 4EF4C4 80218024 F7BC0048 */  sdc1      $f28, 0x48($sp)
/* 4EF4C8 80218028 F7BA0040 */  sdc1      $f26, 0x40($sp)
/* 4EF4CC 8021802C F7B80038 */  sdc1      $f24, 0x38($sp)
/* 4EF4D0 80218030 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 4EF4D4 80218034 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 4EF4D8 80218038 8C840148 */  lw        $a0, 0x148($a0)
/* 4EF4DC 8021803C 3C0140E0 */  lui       $at, 0x40e0
/* 4EF4E0 80218040 4481A000 */  mtc1      $at, $f20
/* 4EF4E4 80218044 3C013F19 */  lui       $at, 0x3f19
/* 4EF4E8 80218048 3421999A */  ori       $at, $at, 0x999a
/* 4EF4EC 8021804C 4481F000 */  mtc1      $at, $f30
/* 4EF4F0 80218050 3C014040 */  lui       $at, 0x4040
/* 4EF4F4 80218054 4481E000 */  mtc1      $at, $f28
/* 4EF4F8 80218058 0C09A75B */  jal       get_actor
/* 4EF4FC 8021805C 0000902D */   daddu    $s2, $zero, $zero
/* 4EF500 80218060 24040180 */  addiu     $a0, $zero, 0x180
/* 4EF504 80218064 0C00AB39 */  jal       heap_malloc
/* 4EF508 80218068 0040982D */   daddu    $s3, $v0, $zero
/* 4EF50C 8021806C 0040882D */  daddu     $s1, $v0, $zero
/* 4EF510 80218070 26300008 */  addiu     $s0, $s1, 8
/* 4EF514 80218074 C67A014C */  lwc1      $f26, 0x14c($s3)
/* 4EF518 80218078 C6620144 */  lwc1      $f2, 0x144($s3)
/* 4EF51C 8021807C 3C014028 */  lui       $at, 0x4028
/* 4EF520 80218080 44810800 */  mtc1      $at, $f1
/* 4EF524 80218084 44800000 */  mtc1      $zero, $f0
/* 4EF528 80218088 460010A1 */  cvt.d.s   $f2, $f2
/* 4EF52C 8021808C 46201080 */  add.d     $f2, $f2, $f0
/* 4EF530 80218090 C6600148 */  lwc1      $f0, 0x148($s3)
/* 4EF534 80218094 3C014014 */  lui       $at, 0x4014
/* 4EF538 80218098 44812800 */  mtc1      $at, $f5
/* 4EF53C 8021809C 44802000 */  mtc1      $zero, $f4
/* 4EF540 802180A0 46000021 */  cvt.d.s   $f0, $f0
/* 4EF544 802180A4 46240000 */  add.d     $f0, $f0, $f4
/* 4EF548 802180A8 AE710078 */  sw        $s1, 0x78($s3)
/* 4EF54C 802180AC 46201620 */  cvt.s.d   $f24, $f2
/* 4EF550 802180B0 462005A0 */  cvt.s.d   $f22, $f0
.L802180B4:
/* 4EF554 802180B4 0260202D */  daddu     $a0, $s3, $zero
/* 4EF558 802180B8 02922821 */  addu      $a1, $s4, $s2
/* 4EF55C 802180BC E614001C */  swc1      $f20, 0x1c($s0)
/* 4EF560 802180C0 E6140024 */  swc1      $f20, 0x24($s0)
/* 4EF564 802180C4 E6140020 */  swc1      $f20, 0x20($s0)
/* 4EF568 802180C8 E6380000 */  swc1      $f24, ($s1)
/* 4EF56C 802180CC E616FFFC */  swc1      $f22, -4($s0)
/* 4EF570 802180D0 E61A0000 */  swc1      $f26, ($s0)
/* 4EF574 802180D4 AE000014 */  sw        $zero, 0x14($s0)
/* 4EF578 802180D8 E61E0018 */  swc1      $f30, 0x18($s0)
/* 4EF57C 802180DC E61C000C */  swc1      $f28, 0xc($s0)
/* 4EF580 802180E0 0C099117 */  jal       get_actor_part
/* 4EF584 802180E4 AE000010 */   sw       $zero, 0x10($s0)
/* 4EF588 802180E8 C6200000 */  lwc1      $f0, ($s1)
/* 4EF58C 802180EC 26520001 */  addiu     $s2, $s2, 1
/* 4EF590 802180F0 E440002C */  swc1      $f0, 0x2c($v0)
/* 4EF594 802180F4 C600FFFC */  lwc1      $f0, -4($s0)
/* 4EF598 802180F8 26310030 */  addiu     $s1, $s1, 0x30
/* 4EF59C 802180FC E4400030 */  swc1      $f0, 0x30($v0)
/* 4EF5A0 80218100 C6000000 */  lwc1      $f0, ($s0)
/* 4EF5A4 80218104 E4400034 */  swc1      $f0, 0x34($v0)
/* 4EF5A8 80218108 2A420008 */  slti      $v0, $s2, 8
/* 4EF5AC 8021810C 1440FFE9 */  bnez      $v0, .L802180B4
/* 4EF5B0 80218110 26100030 */   addiu    $s0, $s0, 0x30
/* 4EF5B4 80218114 8FBF0024 */  lw        $ra, 0x24($sp)
/* 4EF5B8 80218118 8FB40020 */  lw        $s4, 0x20($sp)
/* 4EF5BC 8021811C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4EF5C0 80218120 8FB20018 */  lw        $s2, 0x18($sp)
/* 4EF5C4 80218124 8FB10014 */  lw        $s1, 0x14($sp)
/* 4EF5C8 80218128 8FB00010 */  lw        $s0, 0x10($sp)
/* 4EF5CC 8021812C D7BE0050 */  ldc1      $f30, 0x50($sp)
/* 4EF5D0 80218130 D7BC0048 */  ldc1      $f28, 0x48($sp)
/* 4EF5D4 80218134 D7BA0040 */  ldc1      $f26, 0x40($sp)
/* 4EF5D8 80218138 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 4EF5DC 8021813C D7B60030 */  ldc1      $f22, 0x30($sp)
/* 4EF5E0 80218140 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 4EF5E4 80218144 24020002 */  addiu     $v0, $zero, 2
/* 4EF5E8 80218148 03E00008 */  jr        $ra
/* 4EF5EC 8021814C 27BD0058 */   addiu    $sp, $sp, 0x58
