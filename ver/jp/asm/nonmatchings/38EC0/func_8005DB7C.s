.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005DB7C
/* 38F7C 8005DB7C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 38F80 8005DB80 AFB10014 */  sw        $s1, 0x14($sp)
/* 38F84 8005DB84 0080882D */  daddu     $s1, $a0, $zero
/* 38F88 8005DB88 AFB20018 */  sw        $s2, 0x18($sp)
/* 38F8C 8005DB8C 00A0902D */  daddu     $s2, $a1, $zero
/* 38F90 8005DB90 AFB3001C */  sw        $s3, 0x1c($sp)
/* 38F94 8005DB94 00C0982D */  daddu     $s3, $a2, $zero
/* 38F98 8005DB98 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 38F9C 8005DB9C 4487A000 */  mtc1      $a3, $f20
/* 38FA0 8005DBA0 240402A4 */  addiu     $a0, $zero, 0x2a4
/* 38FA4 8005DBA4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 38FA8 8005DBA8 0C00AB29 */  jal       func_8002ACA4
/* 38FAC 8005DBAC AFB00010 */   sw       $s0, 0x10($sp)
/* 38FB0 8005DBB0 0040202D */  daddu     $a0, $v0, $zero
/* 38FB4 8005DBB4 3C108011 */  lui       $s0, %hi(D_8010F188)
/* 38FB8 8005DBB8 2610F188 */  addiu     $s0, $s0, %lo(D_8010F188)
/* 38FBC 8005DBBC 14800003 */  bnez      $a0, .L8005DBCC
/* 38FC0 8005DBC0 AE240020 */   sw       $a0, 0x20($s1)
.L8005DBC4:
/* 38FC4 8005DBC4 080176F1 */  j         .L8005DBC4
/* 38FC8 8005DBC8 00000000 */   nop
.L8005DBCC:
/* 38FCC 8005DBCC 0000282D */  daddu     $a1, $zero, $zero
/* 38FD0 8005DBD0 0080182D */  daddu     $v1, $a0, $zero
.L8005DBD4:
/* 38FD4 8005DBD4 C6000028 */  lwc1      $f0, 0x28($s0)
/* 38FD8 8005DBD8 E4600004 */  swc1      $f0, 4($v1)
/* 38FDC 8005DBDC C600002C */  lwc1      $f0, 0x2c($s0)
/* 38FE0 8005DBE0 24A50001 */  addiu     $a1, $a1, 1
/* 38FE4 8005DBE4 E4600008 */  swc1      $f0, 8($v1)
/* 38FE8 8005DBE8 C6000030 */  lwc1      $f0, 0x30($s0)
/* 38FEC 8005DBEC 28A20028 */  slti      $v0, $a1, 0x28
/* 38FF0 8005DBF0 A0600000 */  sb        $zero, ($v1)
/* 38FF4 8005DBF4 E460000C */  swc1      $f0, 0xc($v1)
/* 38FF8 8005DBF8 1440FFF6 */  bnez      $v0, .L8005DBD4
/* 38FFC 8005DBFC 24630010 */   addiu    $v1, $v1, 0x10
/* 39000 8005DC00 AC800280 */  sw        $zero, 0x280($a0)
/* 39004 8005DC04 AC800284 */  sw        $zero, 0x284($a0)
/* 39008 8005DC08 AC800288 */  sw        $zero, 0x288($a0)
/* 3900C 8005DC0C AC92028C */  sw        $s2, 0x28c($a0)
/* 39010 8005DC10 AC930290 */  sw        $s3, 0x290($a0)
/* 39014 8005DC14 E4940294 */  swc1      $f20, 0x294($a0)
/* 39018 8005DC18 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 3901C 8005DC1C 0260102D */  daddu     $v0, $s3, $zero
/* 39020 8005DC20 E4800298 */  swc1      $f0, 0x298($a0)
/* 39024 8005DC24 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 39028 8005DC28 46800020 */  cvt.s.w   $f0, $f0
/* 3902C 8005DC2C E480029C */  swc1      $f0, 0x29c($a0)
/* 39030 8005DC30 C7A00048 */  lwc1      $f0, 0x48($sp)
/* 39034 8005DC34 46800020 */  cvt.s.w   $f0, $f0
/* 39038 8005DC38 E48002A0 */  swc1      $f0, 0x2a0($a0)
/* 3903C 8005DC3C 8C440010 */  lw        $a0, 0x10($v0)
/* 39040 8005DC40 8E220000 */  lw        $v0, ($s1)
/* 39044 8005DC44 2403FEFF */  addiu     $v1, $zero, -0x101
/* 39048 8005DC48 AE20001C */  sw        $zero, 0x1c($s1)
/* 3904C 8005DC4C 34420200 */  ori       $v0, $v0, 0x200
/* 39050 8005DC50 00431024 */  and       $v0, $v0, $v1
/* 39054 8005DC54 AE220000 */  sw        $v0, ($s1)
/* 39058 8005DC58 3C020001 */  lui       $v0, 1
/* 3905C 8005DC5C AE220080 */  sw        $v0, 0x80($s1)
/* 39060 8005DC60 AE240028 */  sw        $a0, 0x28($s1)
/* 39064 8005DC64 8FBF0020 */  lw        $ra, 0x20($sp)
/* 39068 8005DC68 8FB3001C */  lw        $s3, 0x1c($sp)
/* 3906C 8005DC6C 8FB20018 */  lw        $s2, 0x18($sp)
/* 39070 8005DC70 8FB10014 */  lw        $s1, 0x14($sp)
/* 39074 8005DC74 8FB00010 */  lw        $s0, 0x10($sp)
/* 39078 8005DC78 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 3907C 8005DC7C 03E00008 */  jr        $ra
/* 39080 8005DC80 27BD0030 */   addiu    $sp, $sp, 0x30
