.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A45DC
/* 3A3DBC E00A45DC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3A3DC0 E00A45E0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3A3DC4 E00A45E4 8C83000C */  lw        $v1, 0xc($a0)
/* 3A3DC8 E00A45E8 3C02E00A */  lui       $v0, %hi(func_E00A4650)
/* 3A3DCC E00A45EC 24424650 */  addiu     $v0, $v0, %lo(func_E00A4650)
/* 3A3DD0 E00A45F0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3A3DD4 E00A45F4 2402000A */  addiu     $v0, $zero, 0xa
/* 3A3DD8 E00A45F8 AFA20014 */  sw        $v0, 0x14($sp)
/* 3A3DDC E00A45FC 2402002D */  addiu     $v0, $zero, 0x2d
/* 3A3DE0 E00A4600 AFA40018 */  sw        $a0, 0x18($sp)
/* 3A3DE4 E00A4604 AFA20010 */  sw        $v0, 0x10($sp)
/* 3A3DE8 E00A4608 8C620000 */  lw        $v0, ($v1)
/* 3A3DEC E00A460C 28420003 */  slti      $v0, $v0, 3
/* 3A3DF0 E00A4610 14400005 */  bnez      $v0, .LE00A4628
/* 3A3DF4 E00A4614 27A40010 */   addiu    $a0, $sp, 0x10
/* 3A3DF8 E00A4618 0C080120 */  jal       func_E0200480
/* 3A3DFC E00A461C 00000000 */   nop
/* 3A3E00 E00A4620 0802918F */  j         .LE00A463C
/* 3A3E04 E00A4624 00000000 */   nop
.LE00A4628:
/* 3A3E08 E00A4628 0C080120 */  jal       func_E0200480
/* 3A3E0C E00A462C 00000000 */   nop
/* 3A3E10 E00A4630 8C430000 */  lw        $v1, ($v0)
/* 3A3E14 E00A4634 34630002 */  ori       $v1, $v1, 2
/* 3A3E18 E00A4638 AC430000 */  sw        $v1, ($v0)
.LE00A463C:
/* 3A3E1C E00A463C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3A3E20 E00A4640 03E00008 */  jr        $ra
/* 3A3E24 E00A4644 27BD0028 */   addiu    $sp, $sp, 0x28
