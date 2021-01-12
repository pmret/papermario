.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80145070
/* DB770 80145070 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB774 80145074 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB778 80145078 00821024 */  and       $v0, $a0, $v0
/* DB77C 8014507C 00021080 */  sll       $v0, $v0, 2
/* DB780 80145080 3C038015 */  lui       $v1, %hi(D_80157960)
/* DB784 80145084 8C637960 */  lw        $v1, %lo(D_80157960)($v1)
/* DB788 80145088 AFBF0014 */  sw        $ra, 0x14($sp)
/* DB78C 8014508C AFB00010 */  sw        $s0, 0x10($sp)
/* DB790 80145090 00431021 */  addu      $v0, $v0, $v1
/* DB794 80145094 8C500000 */  lw        $s0, ($v0)
/* DB798 80145098 0C00AB0A */  jal       general_heap_malloc
/* DB79C 8014509C 240400F0 */   addiu    $a0, $zero, 0xf0
/* DB7A0 801450A0 0040202D */  daddu     $a0, $v0, $zero
/* DB7A4 801450A4 14800003 */  bnez      $a0, .L801450B4
/* DB7A8 801450A8 AE04001C */   sw       $a0, 0x1c($s0)
.L801450AC:
/* DB7AC 801450AC 0805142B */  j         .L801450AC
/* DB7B0 801450B0 00000000 */   nop
.L801450B4:
/* DB7B4 801450B4 3C024003 */  lui       $v0, 0x4003
/* DB7B8 801450B8 8E030000 */  lw        $v1, ($s0)
/* DB7BC 801450BC 3C013F80 */  lui       $at, 0x3f80
/* DB7C0 801450C0 44810000 */  mtc1      $at, $f0
/* DB7C4 801450C4 00621825 */  or        $v1, $v1, $v0
/* DB7C8 801450C8 AE030000 */  sw        $v1, ($s0)
/* DB7CC 801450CC AC800000 */  sw        $zero, ($a0)
/* DB7D0 801450D0 AC800004 */  sw        $zero, 4($a0)
/* DB7D4 801450D4 AC800008 */  sw        $zero, 8($a0)
/* DB7D8 801450D8 AC80000C */  sw        $zero, 0xc($a0)
/* DB7DC 801450DC AC800010 */  sw        $zero, 0x10($a0)
/* DB7E0 801450E0 AC800014 */  sw        $zero, 0x14($a0)
/* DB7E4 801450E4 AC800018 */  sw        $zero, 0x18($a0)
/* DB7E8 801450E8 E480001C */  swc1      $f0, 0x1c($a0)
/* DB7EC 801450EC E4800020 */  swc1      $f0, 0x20($a0)
/* DB7F0 801450F0 0C0504FE */  jal       func_801413F8
/* DB7F4 801450F4 E4800024 */   swc1     $f0, 0x24($a0)
/* DB7F8 801450F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* DB7FC 801450FC 8FB00010 */  lw        $s0, 0x10($sp)
/* DB800 80145100 03E00008 */  jr        $ra
/* DB804 80145104 27BD0018 */   addiu    $sp, $sp, 0x18
