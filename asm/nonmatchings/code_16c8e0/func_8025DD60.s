.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025DD60
/* 18C640 8025DD60 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 18C644 8025DD64 AFB1001C */  sw        $s1, 0x1c($sp)
/* 18C648 8025DD68 0080882D */  daddu     $s1, $a0, $zero
/* 18C64C 8025DD6C AFBF0028 */  sw        $ra, 0x28($sp)
/* 18C650 8025DD70 AFB30024 */  sw        $s3, 0x24($sp)
/* 18C654 8025DD74 AFB20020 */  sw        $s2, 0x20($sp)
/* 18C658 8025DD78 AFB00018 */  sw        $s0, 0x18($sp)
/* 18C65C 8025DD7C 8E3000C0 */  lw        $s0, 0xc0($s1)
/* 18C660 8025DD80 00A0902D */  daddu     $s2, $a1, $zero
/* 18C664 8025DD84 02129821 */  addu      $s3, $s0, $s2
/* 18C668 8025DD88 826308BC */  lb        $v1, 0x8bc($s3)
/* 18C66C 8025DD8C 10600005 */  beqz      $v1, .L8025DDA4
/* 18C670 8025DD90 24020001 */   addiu    $v0, $zero, 1
/* 18C674 8025DD94 10620018 */  beq       $v1, $v0, .L8025DDF8
/* 18C678 8025DD98 00121080 */   sll      $v0, $s2, 2
/* 18C67C 8025DD9C 0809779B */  j         .L8025DE6C
/* 18C680 8025DDA0 00000000 */   nop      
.L8025DDA4:
/* 18C684 8025DDA4 3C013F99 */  lui       $at, 0x3f99
/* 18C688 8025DDA8 3421999A */  ori       $at, $at, 0x999a
/* 18C68C 8025DDAC 44810000 */  mtc1      $at, $f0
/* 18C690 8025DDB0 AFA00014 */  sw        $zero, 0x14($sp)
/* 18C694 8025DDB4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 18C698 8025DDB8 8E250058 */  lw        $a1, 0x58($s1)
/* 18C69C 8025DDBC 8E26005C */  lw        $a2, 0x5c($s1)
/* 18C6A0 8025DDC0 8E270060 */  lw        $a3, 0x60($s1)
/* 18C6A4 8025DDC4 0C01C82C */  jal       func_800720B0
/* 18C6A8 8025DDC8 24040004 */   addiu    $a0, $zero, 4
/* 18C6AC 8025DDCC 00121880 */  sll       $v1, $s2, 2
/* 18C6B0 8025DDD0 02031821 */  addu      $v1, $s0, $v1
/* 18C6B4 8025DDD4 AC6208B0 */  sw        $v0, 0x8b0($v1)
/* 18C6B8 8025DDD8 24020001 */  addiu     $v0, $zero, 1
/* 18C6BC 8025DDDC A26208BC */  sb        $v0, 0x8bc($s3)
/* 18C6C0 8025DDE0 00121100 */  sll       $v0, $s2, 4
/* 18C6C4 8025DDE4 02021021 */  addu      $v0, $s0, $v0
/* 18C6C8 8025DDE8 24030078 */  addiu     $v1, $zero, 0x78
/* 18C6CC 8025DDEC A44308C6 */  sh        $v1, 0x8c6($v0)
/* 18C6D0 8025DDF0 A44008C8 */  sh        $zero, 0x8c8($v0)
/* 18C6D4 8025DDF4 00121080 */  sll       $v0, $s2, 2
.L8025DDF8:
/* 18C6D8 8025DDF8 02021021 */  addu      $v0, $s0, $v0
/* 18C6DC 8025DDFC 00122100 */  sll       $a0, $s2, 4
/* 18C6E0 8025DE00 02042021 */  addu      $a0, $s0, $a0
/* 18C6E4 8025DE04 848308C6 */  lh        $v1, 0x8c6($a0)
/* 18C6E8 8025DE08 8C4208B0 */  lw        $v0, 0x8b0($v0)
/* 18C6EC 8025DE0C 3C0142C8 */  lui       $at, 0x42c8
/* 18C6F0 8025DE10 44810000 */  mtc1      $at, $f0
/* 18C6F4 8025DE14 3C014224 */  lui       $at, 0x4224
/* 18C6F8 8025DE18 44812000 */  mtc1      $at, $f4
/* 18C6FC 8025DE1C 44831000 */  mtc1      $v1, $f2
/* 18C700 8025DE20 00000000 */  nop       
/* 18C704 8025DE24 468010A0 */  cvt.s.w   $f2, $f2
/* 18C708 8025DE28 8C43000C */  lw        $v1, 0xc($v0)
/* 18C70C 8025DE2C 46001083 */  div.s     $f2, $f2, $f0
/* 18C710 8025DE30 E4620044 */  swc1      $f2, 0x44($v1)
/* 18C714 8025DE34 46041082 */  mul.s     $f2, $f2, $f4
/* 18C718 8025DE38 00000000 */  nop       
/* 18C71C 8025DE3C C6200058 */  lwc1      $f0, 0x58($s1)
/* 18C720 8025DE40 E4600004 */  swc1      $f0, 4($v1)
/* 18C724 8025DE44 C620005C */  lwc1      $f0, 0x5c($s1)
/* 18C728 8025DE48 46020000 */  add.s     $f0, $f0, $f2
/* 18C72C 8025DE4C E4600008 */  swc1      $f0, 8($v1)
/* 18C730 8025DE50 848208C8 */  lh        $v0, 0x8c8($a0)
/* 18C734 8025DE54 C6200060 */  lwc1      $f0, 0x60($s1)
/* 18C738 8025DE58 44821000 */  mtc1      $v0, $f2
/* 18C73C 8025DE5C 00000000 */  nop       
/* 18C740 8025DE60 468010A0 */  cvt.s.w   $f2, $f2
/* 18C744 8025DE64 46020000 */  add.s     $f0, $f0, $f2
/* 18C748 8025DE68 E460000C */  swc1      $f0, 0xc($v1)
.L8025DE6C:
/* 18C74C 8025DE6C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 18C750 8025DE70 8FB30024 */  lw        $s3, 0x24($sp)
/* 18C754 8025DE74 8FB20020 */  lw        $s2, 0x20($sp)
/* 18C758 8025DE78 8FB1001C */  lw        $s1, 0x1c($sp)
/* 18C75C 8025DE7C 8FB00018 */  lw        $s0, 0x18($sp)
/* 18C760 8025DE80 03E00008 */  jr        $ra
/* 18C764 8025DE84 27BD0030 */   addiu    $sp, $sp, 0x30
