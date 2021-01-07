.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021D290_6A4490
/* 6A4490 8021D290 8C8400C0 */  lw        $a0, 0xc0($a0)
/* 6A4494 8021D294 8C83000C */  lw        $v1, 0xc($a0)
/* 6A4498 8021D298 24020055 */  addiu     $v0, $zero, 0x55
/* 6A449C 8021D29C AC620030 */  sw        $v0, 0x30($v1)
/* 6A44A0 8021D2A0 8C83000C */  lw        $v1, 0xc($a0)
/* 6A44A4 8021D2A4 2402002A */  addiu     $v0, $zero, 0x2a
/* 6A44A8 8021D2A8 AC620034 */  sw        $v0, 0x34($v1)
/* 6A44AC 8021D2AC 8C82000C */  lw        $v0, 0xc($a0)
/* 6A44B0 8021D2B0 240300FF */  addiu     $v1, $zero, 0xff
/* 6A44B4 8021D2B4 AC430038 */  sw        $v1, 0x38($v0)
/* 6A44B8 8021D2B8 8C82000C */  lw        $v0, 0xc($a0)
/* 6A44BC 8021D2BC AC430040 */  sw        $v1, 0x40($v0)
/* 6A44C0 8021D2C0 8C83000C */  lw        $v1, 0xc($a0)
/* 6A44C4 8021D2C4 240200AF */  addiu     $v0, $zero, 0xaf
/* 6A44C8 8021D2C8 AC620044 */  sw        $v0, 0x44($v1)
/* 6A44CC 8021D2CC 8C83000C */  lw        $v1, 0xc($a0)
/* 6A44D0 8021D2D0 240200EF */  addiu     $v0, $zero, 0xef
/* 6A44D4 8021D2D4 AC620048 */  sw        $v0, 0x48($v1)
/* 6A44D8 8021D2D8 03E00008 */  jr        $ra
/* 6A44DC 8021D2DC 24020002 */   addiu    $v0, $zero, 2
